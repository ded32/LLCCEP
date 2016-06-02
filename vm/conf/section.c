#include <string.h>

#include "section.h"

static const unsigned __SECT_TYPES_SZ = 3;
static const char * const __sect_types[] = {
	"hdd",
	"display",
	"ram"
};

static const unsigned __FIELD_TYPES_SZ = 4;
static const char * const __field_types[] = {
	"size",
	"width",
	"height",
	"path"
};

enum sect_t get_section_type(const char * const str)
{
	unsigned i;
	for (i = 0; i < __SECT_TYPES_SZ; i++)
		if (!strcmp(str, __sect_types[i]))
			break;

	return (enum sect_t)i;
}

enum sect_field_t get_field_type(const char * const str)
{
	unsigned i;
	for (i = 0; i < __FIELD_TYPES_SZ; i++)
		if (!strcmp(str, __field_types[i]))
			break;

	return (enum sect_field_t)i;
}

