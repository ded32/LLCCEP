#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <list.h>

#if defined(__cplusplus)
extern "C" {
#endif

extern struct undirected_list *configuration_file_data;

struct undirected_list *read_vm_configuration_file(FILE *fd);

#if defined(__cplusplus)
}
#endif

#endif // READER_H
