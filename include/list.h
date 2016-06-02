#ifndef LIST_H
#define LIST_H

#if defined(__cplusplus)
extern "C" {
#endif

struct unidirected_list {
	void *data;
	struct list *next;
};

struct unidirected_list *undirected_list_init(void *data);
struct unidirected_list *unidirected_list_insert_head(
	struct unidirected_list *last_head,
	void *data4new);
struct unidirected_list *unidirected_list_remove_head(
	struct unidirected_list *head);
void unidirected_list_delete(struct unidirected_list *head);

#if defined(__cplusplus)
}
#endif

#endif // LIST_H
