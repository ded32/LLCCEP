#include <DotViz++.hpp>
#include "ast.hpp"
#include "dump.hpp"

#define ADD_CHILD(tree, string) (tree)->insert_child(new LLCCEP_SiHi::ast({}, 0, (string)));

int main()
{
	LLCCEP_SiHi::ast syntaxTree({}, 0, "Main");

	ADD_CHILD(&syntaxTree, "int")
	ADD_CHILD(&syntaxTree, "(void)")
	ADD_CHILD(&syntaxTree, "return")
	ADD_CHILD(syntaxTree.get_children()[2], "-1")

	LLCCEP_SiHi::dump_ast("out.gv", "ast_dump", syntaxTree);
	DotViz::dvRender("out.gv", "out.pdf");

	return 0;
}
