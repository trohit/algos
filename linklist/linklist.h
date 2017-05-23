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
node* new_node(int key)
{

	node *bogey = malloc(sizeof(node));
	if (!bogey) {
		// TODO: add error handling code here
		return NULL;
	}
	bogey->info = key;
	bogey->next = NULL;
	return bogey;
}
void disp_list(node *list)
{
	if (list == NULL) return;
	node *tmp;
	tmp = list;
        printf("\n");
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
/*
 * detects if there is a loop in the linklist.
 * @params:
 * 	start of the linklist.
 * @return:
 * 	first node from where the loop starts if it exists
 * 	NULL if there is no loop.
 */
node* detect_loop(node *head)
{
	node *slow = head;
	node *fast = NULL;
	if (head == NULL || head->next == NULL) {
	       return NULL;
	}
	fast = slow->next;
	while (fast != NULL) {
		/*
		 * we want the node before the start of the loop.
		 */
		if (slow->next == fast) {
			printf("Found a loop at [%u]", slow->info);
			return slow;
		}
		slow = slow->next;
		fast = slow->next;
	}
        return NULL;
}
node* insert_loop_node(node *head, node *rogue)
{
	node *iter = head;
	if (!iter) return NULL;
	while (iter->next) iter = iter->next;

	iter->next = rogue;
	rogue->next = head->next;
	return head;
}
void swap(node *a, node *b)
{
    int t;
    t = a->info;
    a->info = b->info;
    b->info = t;
}

/*
 * Fetches node at offset specified, starting from 0.
 * returns NULL if offset is invalid.
 */ 
node* get_elm_at(node *head, int pos)
{
    node *tmp = head;
    uint offset = 0;
    while (offset != pos) {
        if (tmp == NULL) return NULL;
        tmp = tmp->next;
        offset++;
    }
    return tmp;
}

int count(node *head)
{
    node *tmp = head;
    int len = 0;
    if (tmp == NULL)
        return len;
    else 
        len++;
    while (tmp->next) {
        //printf("%u ", tmp->data);
        tmp = tmp->next;
        len++;
    }
    return len;
}

void sort_list(node *head)
{
    int len = count(head);
    node *t = head;
    for (int i = 0; i < len; i++) {
        t = head;
        for (int j = 0; j < len - 1; j++) {
            if (t && t->next) {
                printf("\nComparing %u<>%u:", t->info, t->next->info);
                if (t->info > t->next->info) {
                    printf("SWAPPED");
                    swap(t, t->next);
                }
                t = t->next;
            }
        }
        disp_list(head);
    }
}

bool is_linklist_palindrome(node *head)
{
    node *rev = head;
    node *dup = NULL;
    int pos = 0;
    if (rev == NULL)
        return true;
    int len = count(head);
    while (pos != len/2) {
        dup = insert_list_stack(dup, rev->info);
        rev = rev->next;
        pos++;
    }
    if (len%2) {
        rev = rev->next;
    } 
    //compare both lists
    while (dup && rev) {
        if (dup->info != rev->info) {
            return false;
        }
        dup = dup->next;
        rev = rev->next;
    }
    return true;

}

#endif /* __LINKLIST_H__ */
