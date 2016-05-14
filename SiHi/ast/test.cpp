#include "ast.hpp"

int main()
{
	LLCCEP_SiHi::ast syntaxTree;

	for (int i = 0; i < 800; i++) {
		LLCCEP_SiHi::ast *ptr = new LLCCEP_SiHi::ast({}, 0, "hell");
		syntaxTree.insert_child(ptr);
	}

	return 0;
}
