#include <DotViz/DotViz++.hpp>
#include "ast.hpp"
#include "dump.hpp"

int main()
{
	LLCCEP_SiHi::ast syntaxTree;

	for (int i = 0; i < 15; i++) {
		LLCCEP_SiHi::ast *ptr = new LLCCEP_SiHi::ast({}, 0, "hell");
		syntaxTree.insert_child(ptr);
	}

	LLCCEP_SiHi::dump_tree("out.gv", syntaxTree);
	DotViz::dvRender("pdf", "out.gv", "out.pdf");

	return 0;
}
