#ifndef INIT_H
#define INIT_H

#include <stddef.h>
#include <stdint.h>
#include <list.h>

#if defined(__linux__)
#include <linux/limits.h>
#else
#include <limits.h>
#endif

struct init_data {
	size_t ramS;

	uint16_t dispW;
	uint16_t dispH;

	struct undirected_list *devD;
};

struct init_data process_configuration(struct undirected_list *data);
void setup(struct init_data data);

#endif // INIT_H
