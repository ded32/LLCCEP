#ifndef SECTION_H
#define SECTION_H

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__linux__)
#include <linux/limits.h>
#endif

#include <limits.h>

#include <list.h>

enum sect_t {
	SECT_T_HDD     = 0,
	SECT_T_DISPLAY = 1,
	SECT_T_RAM     = 2,
	SECT_T_INVALID = 3
};

enum sect_field_t {
	SECT_FIELD_T_ALLOC   = 0,
	SECT_FIELD_T_WIDTH   = 1,
	SECT_FIELD_T_HEIGHT  = 2,
	SECT_FIELD_T_PATH    = 3,
	SECT_FIELD_T_INVALID = 4
};

struct section_field {
	enum sect_field_t type;
	char str[PATH_MAX];
};

struct section {
	enum sect_t type;
	struct unidirected_list *fields;
};

enum sect_t get_section_type(const char * const str);
enum sect_field_t get_field_type(const char * const str);

#if defined(__cplusplus)
}
#endif

#endif // SECTION_H
