/*************************************************
 * SiHi compiler main file
 *
 * Author: Andrew Bezzubtsev
 * Date: 31/08/2016
 * File: main.cpp
 *
 * This file contains the master function, that
 * manages all the resources and generates
 * target code(assembly/bytecode).
 ************************************************/
#include <cstdio>
#include <DotViz/DotViz++.hpp>

#include "ast/ast.hpp"
#include "SiHiParser.hpp"

/*************************************************
 * Intermodular variables
 ************************************************/
extern FILE *yyin;
::std::string yyfilename;

/*************************************************
 * Intermodular functions
 ************************************************/
extern int yyparse(LLCCEP_SiHi::ast **parsingResult);

/*************************************************
 * Master
 ************************************************/
int main()
{
	yyfilename = "stdin";
	yyin = stdin;

	LLCCEP_SiHi::ast *parsingResult;
	yyparse(&parsingResult);

	if (parsingResult) {
		parsingResult->dumpImage("out.ast");
		delete parsingResult;

		DotViz::dvRender("out.ast", "out.png");
		::std::remove("out.ast");
	} else {
		::std::cerr << "Invalid input\n";
	}

	return 0;
}
