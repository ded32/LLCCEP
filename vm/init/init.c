#include <assert.h>
#include <stdio.h>

#include "./../conf/section.h"
#include "./init.h"

#define ERROR(data, ...) {fprintf(stderr, data, __VA_ARGS__); exit(EXIT_FAILURE);}

static int16_t __static_getW(struct section *sect)
{
	assert(sect);

	struct undirected_list *fields = sect->fields;
	while (fields) {
		if (((struct section_field *)fields->data)->type == SECT_FIELD_T_WIDTH)
			return str2uint16_t(((struct section_field *)fields->data)->str);

		fields = fields->next;
	}

	ERROR("Error!\nNo display width!\n");
	return 0;
}

static uint16_t __static_getH(struct section *sect)
{
	assert(sect);

	struct undirected_list *fields = sect->fields;
	while (fields) {
		if (((struct section_field *)fields->data)->type == SECT_FIELD_T_HEIGHT)
			return str2uint16_t(((struct section_field *)fields->data)->str);

		fields = fields->next;
	}

	ERROR("Error!\nNo display height!\n");
	return 0;
}

static size_t __static_getRamS(struct section *sect)
{
	assert(sect);

	struct undirected_list *fields = sect->fields;
	while (fields) {
		if (((struct section_field *)fields->data)->type == SECT_FIELD_T_ALLOC)
			return str2size_t(((struct section_field *)fields->data)->str);

		fields = fields->next;
	}

	ERROR("Error!\nNo mem size!\n");
	return 0;
}

struct init_data process_configuration(struct undirected_list *data)
{
	assert(data);

	struct init_data res = {};
	while (data) {
		struct section *sect = (struct section *)data->data;
		if (!sect)
			continue;

		switch (sect->type) {
			case SECT_T_HDD:
				res.devD = undirected_list_insert_head(sect->fields->data.str);
				break;

			case SECT_T_DISPLAY:
				res.dispW = __static_getW(sect);
				res.dispH = __static_getH(sect);
				break;

			case SECT_T_RAM:
				res.ramS = __static_getRamS(sect);
				break;

			default:
				break;
		}
	}	
}
