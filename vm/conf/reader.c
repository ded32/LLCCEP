#include <stdio.h>
#include <assert.h>
#include <list.h>

#include "reader.h"
#include "parser.h"

struct unidirected_list *read_vm_configuration_file(FILE *fd)
{
	assert(fd);

	yyin = fd;
	yyparse();
}
