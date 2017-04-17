/*
 * Doubly linklist implementation
 */ 
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
typedef struct node {
	struct node* prev;
	struct node* next;
	int info;
} node_t;
node_t *head = NULL;
int is_empty(node_t *elm)
{
	return (elm?0:1);
}
node_t* insert(node_t* list, int i)
{
	node_t *iter = list;
	node_t *elm = NULL;
	elm = malloc(sizeof (node_t));
	if (!elm) {
		return NULL;
	}
	elm->info = i;
	// get to the last node
	while (iter && iter->next) {
		iter = iter->next;
	}
	if (iter) {
		// subsequent time node is added.
		iter->next = elm;
		elm->prev = iter; 
		elm->next = NULL; 
	} else {
		// first time node is added.
		elm->next = elm->prev = NULL;
		list = elm;
	}
	return list;
}

void disp(node_t *list)
{
	node_t *iter = list;
	int is_first = 1;
	while (iter) {
		if (!is_first) {
			printf("->");
		} else {
			is_first = 0;
		}
		printf("%u", iter->info);
		iter = iter->next;
	}
	printf("\n");
}

int main()
{
	head = insert(head, 45);
	head = insert(head, 46);
	head = insert(head, 47);
	head = insert(head, 48);
	disp(head);
	return 0;
}
