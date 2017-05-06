#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
	int info;
	struct node *next;
} node;

int is_empty(node *list)
{
	if (NULL == list) {
		return true;
	}
	return false;
}
void disp_list(node *list) 
{
	if (list == NULL) return;
	node *tmp;
	tmp = list;
	while (tmp) {
		printf("[%u]", tmp->info);
		if (tmp->next) {
			printf("->");
			tmp = tmp->next;
		} else {
			printf("\n");
			break;
		}
	}
	printf("End-of-list\n");
}
node* insert_list(node *head, int i)
{
	node *bogey = malloc(sizeof(node));
	if (bogey) {
		bogey->info = i;
	}

	if (is_empty(head)) {
		head = bogey;
		bogey->next = NULL;
	} else {
		node *tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = bogey;
	}
	return head;
}
node* insert_list_stack(node *head, int i)
{
	node *bogey = malloc(sizeof(node));
	if (bogey) {
		bogey->info = i;
	}

	if (is_empty(head)) {
		head = bogey;
		bogey->next = NULL;
	} else {
		bogey->next = head;
		head = bogey;
	}
	return head;
}
#endif /* __LINKLIST_H__ */
