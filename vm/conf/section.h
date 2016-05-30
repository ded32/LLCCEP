#ifndef SECTION_H
#define SECTION_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <limits.h>

enum sect_t {
	SECT_T_HDD,
	SECT_T_DISPLAY,
	SECT_T_RAM
};

enum sect_field_t {
	SECT_FIELD_T_ALLOC,
	SECT_FIELD_T_WIDTH,
	SECT_FIELD_T_HEIGHT,
	SECT_FIELD_T_PATH
};

struct section_field {
	enum sect_field_t type;
	union {
		char str[PATH_MAX];
		size_t num;
	} val;
};

struct section {
	enum sect_t type;
	struct section_field *fields;
};

struct section *section_init(enum sect_t type,
                             struct section_field *fields);
void section_delete(struct section *sect);

#if defined(__cplusplus)
}
#endif

#endif // SECTION_H
