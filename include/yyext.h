#ifndef YYEXT_H
#define YYEXT_H

#include <stdio.h>

struct file_queue_member {
	char *path;
};

struct file_queue {
	struct file_queue_member *members;
	size_t membersno;
};

struct file_queue *file_queue_create

void readfile(FILE *in, char **buf);

#endif /* YYEXT_H */
