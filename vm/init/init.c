#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <convert.h>

#include "./../conf/section.h"
#include "./init.h"

#define ERROR(data, ...) {fprintf(stderr, data, ##__VA_ARGS__); exit(EXIT_FAILURE);}

#define EXTRACT_SECTION_PROPERTY(__f_used, __data, __prop_t, __res) \
({ \
	while (__data) { \
		struct section_field *field = (struct section_field *)(__data->data); \
		\
		if (field->type == __prop_t) { \
			__res = __f_used(field->str); \
			break; \
		} \
		\
		__data = __data->next; \
	} \
})

struct init_data process_configuration(struct unidirected_list *data)
{
	assert(data);

	struct init_data res = { };
	while (data) {
		struct section *sect = (struct section *)data->data;
		if (!sect) {
			fprintf(stderr, "Zero section at %p!\n", 
			        data + offsetof(struct unidirected_list, data));
			break;
		}

		if (sect->type == SECT_T_DISPLAY) {
			EXTRACT_SECTION_PROPERTY(str2uint16_t, sect->fields, SECT_FIELD_T_WIDTH, res.dispW);
			EXTRACT_SECTION_PROPERTY(str2uint16_t, sect->fields, SECT_FIELD_T_HEIGHT, res.dispH);
		}

		data = data->next;
	}

	return res;
}
