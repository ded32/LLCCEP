#ifndef COMMON_AST_HPP
#define COMMON_AST_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include <STDExtras.hpp>
#include <STLExtras.hpp>
#include <DotViz/DotViz++.hpp>

#define AST_OK DEFAULT_CHECK_BLOCK(this, ok(), true)

namespace LLCCEP {
	template<typename lexemType>
	class ast {
	public:
		ast();
		ast(const ast<lexemType> &from);
		explicit ast(::std::string inPath);
		explicit ast(lexemType value, ::std::vector<ast<lexemType> *> childrenToCopy = 
				              ::std::vector<ast<lexemType> *>{});
		~ast();
		
		void addChild(ast<lexemType> *child);
		::std::vector<ast<lexemType> *> getChildren() const;

		void value(lexemType newLexemData);
		lexemType value() const;

		void loadPlain(::std::string inPath);

		void dumpPlain(::std::string outPath) const;
		void dumpImage(::std::string outPath) const;

	protected:
		bool ok() const;
		void clear();

	private:
		void loadPlain(::std::istream &in);

		void dumpPlain(::std::ostream &out) const;
		void dumpImage(DotViz::DVGraph &graph) const;

		::std::vector<ast<lexemType> *> children;
		ast<lexemType> *parent;
		lexemType lexemData;
	};
}

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
			LLCCEP::ast<lexemType> *newChild = new (::std::nothrow) LLCCEP::ast<lexemType>(i->value(), i->getChildren());
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
			LLCCEP::ast<lexemType> *newChild = new (::std::nothrow) LLCCEP::ast<lexemType>(i->lexemData, i->getChildren());
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
void LLCCEP::ast<lexemType>::addChild(LLCCEP::ast<lexemType> *child)
{
	AST_OK

	if (!child) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"An attempt of insertion a null child"))
	}

	if (child->parent) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Ast [0x%p] already has got parent [0x%p]",
			child, child->parent))
	}

	if (!child->ok()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"An attempt of insertion not ok child [0x%p]",
			child))
	}

	child->parent = this;
	children.push_back(child);

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
		if (::std::find(parent->children.begin(), parent->children.end(), this) == 
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
		LLCCEP::ast<lexemType> newChild;
		newChild.loadPlain(in);
		addChild(newChild);
	}

	AST_OK
}

template<typename lexemType>
void LLCCEP::ast<lexemType>::dumpPlain(::std::ostream &out) const
{
	AST_OK

	out << reinterpret_cast<uint64_t>(this) << " [" 
	    << children.size() << " children]: " << lexemData << "\n";

	for (const auto &i: children)
		i->dumpPlain(out);

	AST_OK
}

template<typename lexemType>
void LLCCEP::ast<lexemType>::dumpImage(DotViz::DVGraph &graph) const
{
	AST_OK

	graph.node(reinterpret_cast<uint64_t>(this), lexemData.toString());

	for (const auto &i: children) {
		i->dumpImage(graph);
		graph.link(reinterpret_cast<uint64_t>(this),
			   reinterpret_cast<uint64_t>(i));
	}

	AST_OK
}

#endif // COMMON_AST_HPP
