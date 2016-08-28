#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include <STDExtras.hpp>
#include <DotViz++.hpp>

#include "./../lexem/lexem.hpp"

#define AST_OK DEFAULT_CHECK_BLOCK(this, ok(), true)

template<typename lexemType>
LLCCEP::ast<lexemType>::ast():
	children(),
	parent(0),
	lexemData()
{ }

template<typename lexemType>
LLCCEP::ast<lexemType>::ast(const LLCCEP::ast<lexemType> &from):
	children(),
	parent(0),
	lexemData(from.value())
{
	for (const auto &i: from.getChildren()) {
		if (i) {
			LLCCEP::ast newChild(i->value(), i->getChildren());
			addChild(newChild);
		}
	}
}

template<typename lexemType>
LLCCEP::ast<lexemType>::ast(lexemType value, ::std::vector<LLCCEP::ast<lexemType> *> childrenToCopy):
	children(),
	parent(0),
	lexemData(value)
{
	for (const auto &i: childrenToCopy) {
		if (i) {
			LLCCEP::ast newChild(i->val, i->getChildren());
			addChild(newChild);
		}
	}
}

template<typename lexemType>
LLCCEP::ast<lexemType>::~ast()
{
	clear();

	if (parent) {
		auto thisIterator = vec_find(parent->children, this);

		if (thisIterator != parent->children.end())
			parent->children.erase(thisIterator);
	}
}

template<typename lexemType>
void LLCCEP::ast<lexemType>::addChild(const LLCCEP::ast<lexemType> &child)
{
	AST_OK

	LLCCEP::ast *ptr = new LLCCEP::ast(child);
	ptr->parent = this;
	children.push_back(ptr);

	AST_OK
}

template<typename lexemType>
::std::vector<LLCCEP::ast<lexemType> *> LLCCEP::ast<lexemType>::getChildren() const
{
	AST_OK

	return children;
}

template<typename lexemType>
void LLCCEP::ast<lexemType>::value(lexemType newLexemData)
{
	AST_OK

	lexemData = newLexemData;

	AST_OK
}

template<typename lexemType>
lexemType LLCCEP::ast<lexemType>::value() const
{
	AST_OK

	return lexemData;
}

template<typename lexemType>
void LLCCEP::ast<lexemType>::loadPlain(::std::string inPath)
{
	AST_OK

	clear();
	::std::ifstream input(inPath);
	if (input.fail()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Can't open '%s' for loading ast: %s",
			inPath.c_str(), ::std::strerror(errno)));
	}

	loadPlain(input);

	AST_OK
}

template<typename lexemType>
void LLCCEP::ast<lexemType>::dumpPlain(::std::string outPath) const
{
	AST_OK

	::std::ofstream output(outPath);
	if (output.fail()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Can't open '%s' for ast dump: %s",
			outPath.c_str(), ::std::strerror(errno)));
	}

	dumpPlain(output);

	output.close();

	AST_OK
}

template<typename lexemType>
void LLCCEP::ast<lexemType>::dumpImage(::std::string outPath) const
{
	AST_OK

	DotViz::DVGraph output;
	output.begin(outPath, "astDump");

	dumpImage(output);

	output.end();

	AST_OK
}

template<typename lexemType>
bool LLCCEP::ast<lexemType>::ok() const
{
	for (size_t i = 0; i < children.size(); i++) {
		if (!children[i] || !children[i]->ok()) {
			::std::cerr << "Bad child at [" << i << "]\n";
			return false;
		}
	}

	if (parent) {
		if (vec_find(parent->children, this) == 
		    parent->children.end()) {
			::std::cerr << "Ancestor at [0x" << parent
			            << "] doesn't have [0x" << this
				    << "] child\n";
			return false;
		}
	}

	return true;
}

template<typename lexemType>
void LLCCEP::ast<lexemType>::clear()
{
	for (const auto &i: children)
		delete i;

	children.clear();
	lexemData = lexemType{};
}

template<typename lexemType>
void LLCCEP::ast<lexemType>::loadPlain(::std::istream &in)
{
	AST_OK

	size_t childrenAmount = 0;
	uint64_t oldPtr = 0;
	
	in >> oldPtr >> "[" >> childrenAmount >> "children" >> "]"
	   >> ":" >> lexemData;

	for (size_t i = 0; i < childrenAmount; i++) {
		LLCCEP::ast newChild;
		newChild.loadPlain(in);
		addChild(newChild);
	}

	AST_OK
}

template<typename lexemType>
void LLCCEP::ast<lexemType>::dumpPlain(::std::ostream &out) const
{
	AST_OK

	out << static_cast<uint64_t>(this) << " [" 
	    << children.size() << "children]: " << lexemData << "\n";

	for (const auto &i: children)
		children[i]->dumpPlain(out);

	AST_OK
}

template<typename lexemType>
void LLCCEP::ast<lexemType>::dumpImage(DotViz::DVGraph &graph) const
{
	AST_OK

	graph.node(static_cast<uint64_t>(this), lexemData.toString());

	for (const auto &i: children) {
		children[i]->dumpImage(graph);
		graph.link(static_cast<uint64_t>(this),
			   static_cast<uint64_t>(i));
	}

	AST_OK
}
