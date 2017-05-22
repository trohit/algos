/*
 * Simple Linklist inplementation as a stack
 */
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "linklist.h"
node *head;
int main()
{
	//node *rogue = new_node(50);

	//disp_list(head);
	//head = insert_list(head, 20);
	//head = insert_list(head, 30);
	//head = insert_list(head, 40);
	head = insert_list_stack(head, 10);
	head = insert_list_stack(head, 20);
	head = insert_list_stack(head, 30);
	head = insert_list_stack(head, 40);
	head = insert_list_stack(head, 50);
	
	//head = insert_loop_node(head, rogue);
	//disp_list(head);
        //swap(head, head->next);
	disp_list(head);
        sort_list(head);
	disp_list(head);

	return 0;
}
