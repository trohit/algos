/*
 * Program to swap two nodes in a doubly linked list.
 */
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct node {
    struct node *next, *prev;
    int data;
} node;
node *head = NULL;

node *newNode(int key)
{
    node *e = malloc(sizeof(node));
    e->data = key;
    e->next = e->prev = NULL;
    return e;
}

//stacked insert of linklist
node* insert_list(node *head, int key)
{
    node *bogey = newNode(key);
    if (head == NULL) {
        //printf("inserting 1st time");
        head = bogey;
    } else {
        //printf("inserting >1st time");
        bogey->next = head;
        head->prev = bogey;
        head = bogey;
    }
    return head;
}

void displist(node *head)
{
    node *tmp = head;
    printf("\ndisp:");
    while (tmp) {
        printf("%u ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
void displist_rev(node *head)
{
    node *tmp = head;
    if (tmp == NULL)
        return;
    printf("\nrev :");
    while (tmp->next) {
        //printf("%u ", tmp->data);
        tmp = tmp->next;
    }
    // lets go backward
    while (tmp) {
        printf("%u ", tmp->data);
        tmp = tmp-> prev;
    }
    printf("\n");
}
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
/*
 *
 * 1. handle head and elm : neighbors and strangers
 * 2. handle two non head or tail elms: neighbors and strangers
 * 3. handle elm and tail : neighbors and strangers
 * 4. handle head and tail: neighbors and strangers
 *
 *  a -> b -> c -> d
 *    <-   <-   <-
 *
 *  a -> c -> b -> d
 *    <-   <-   <-
 *
 *  head -> a -> b -> c
 *       <-   <-   <-
 *
 *  head -> i -> a -> b
 *       <-   <-   <-
 *
 */    
node* swap(node *head, node *a, node *b) 
{
    bool is_head = false;
    node *tp = NULL;
    node *tn = NULL;

    if (head == a || head == b)  
        is_head = true;
    tp = a->prev;
    tn = a->next;

    // printf("swapping neighbors 
    if (a->next == b) {
        if (b->next)
            b->next->prev = a;
        if (a->prev)
            a->prev->next = b;
        a->next = b->next;
        a->prev = b;
        b->next = a;
        b->prev = tp;
    } else {
        //printf("swap strangers");
        if (b->prev)
            b->prev->next = a;
        if (b->next)
            b->next->prev = a;
        if (a->prev)
            a->prev->next = b;
        if (a->next)
            a->next->prev = b;
        a->prev = b->prev;
        a->next = b->next;
        b->prev = tp;
        b->next = tn;
    }
    if (is_head) {
        if (head == a)
            head = b;
        else
            head = a;
    }

    return head;
}
int main()
{
    int count = 0;
    int key = 0;
    int p1 = 0, p2 = 0;
    node *x = NULL, *y = NULL;
#if 0
    scanf("%u", &count);
    for(int i = 0; i < count ; i++) {
        scanf("%u", &key);
        head = insert_list(head, key);
    }
#endif
    int arr[] = {40,30,20,10};
    count = 4;
    for(int i = 0; i < count ; i++) {
        head = insert_list(head, arr[i]);
    }
    displist(head);
    //displist_rev(head);
    printf("enter positions to swap:");
    scanf("%u %u", &p1 , &p2);
    x = get_elm_at(head, p1);
    y = get_elm_at(head, p2);
    printf("%u<->%u", x->data, y->data);
    head = swap(head, x, y);
    displist(head);
    displist_rev(head);
    return 0;
}
