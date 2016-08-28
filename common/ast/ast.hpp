#ifndef COMMON_AST_HPP
#define COMMON_AST_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include <DotViz++.hpp>

#include "./../lexem/lexem.hpp"

namespace LLCCEP {
	template<typename lexemType>
	class ast {
		ast();
		ast(const ast<lexemType> &from);
		explicit ast(::std::string inPath);
		explicit ast(lexemType value, ::std::vector<ast<lexemType> *> childrenToCopy{});
		~ast();
		
		void addChild(const ast<lexemType> &child);
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
		void loadPlain(::std::istream in);

		void dumpPlain(::std::ostream &out) const;
		void dumpImage(DotViz::DVGraph &graph) const;

		::std::vector<ast<lexemType> *> children;
		ast<lexemType> *parent;
		lexemType lexemData;
	};
}

#endif // COMMON_AST_HPP
