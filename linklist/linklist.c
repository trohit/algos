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
	disp_list(head);
	head = insert_list(head, 1);
	head = insert_list(head, 11);
	head = insert_list(head, 22);
	head = insert_list_stack(head, 32);
	disp_list(head);
	return 0;
}
