#include <list.h>

#include "lexer.h"

int main(void)
{
	strcpy(yyfilename, "stdin");
	yyin = stdin;

	yyparse();

	unidirected_list_delete(configuration_file_data);

	return 0;
}
