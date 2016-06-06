#include <stdio.h>
#include <assert.h>
#include <list.h>

#include "./synthesis/lexer.h"
#include "./synthesis/parser.h"

#include "./reader.h"

struct unidirected_list *read_vm_configuration_file(FILE *fd)
{
	assert(fd);

	yyin = fd;
	yyparse();
	yyin = 0;

	return configuration_file_data;
}
