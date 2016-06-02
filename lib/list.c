#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <list.h>

struct unidirected_list *unidirected_list_init(void *data)
{
	struct unidirected_list *res = (struct undirected_list *)calloc(1, sizeof(*res));

	if (!res) {
		fprintf(stderr, "Can't alloc memory for list head: %s",
		        strerror(errno));

		return 0;
	}

	res->data = data;

	return res;
}

struct unidirected_list *unidirected_list_insert_head(
	struct unidirected_list *last_head,
	void *data4new)
{
	struct unidirected_list *res = unidirected_list_init(data4new);
	res->next = last_head;

	return res;
}

struct unidirected_list *unidirected_list_remove_head(
	struct unidirected_list *head)
{
	struct unidirected_list *res = 0;
	if (!head)
		return 0;

	res = head->next;
	free((void *)head);

	return res;
}

void unidirected_list_delete(struct unidirected_list *head)
{
	while (head) {
		free((void *)head);
		head = head->next;
	}
}
