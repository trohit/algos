#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
        struct _node *left, *right;
        int data;
} node;
int height(node *n)
{
        int lh = 0, rh = 0;
        if (!n) 
                return 0;
        if (n && !n->left && !n->right)
                return 1;
        lh = height(n->left);
        rh = height(n->right);
        return (lh > rh ? lh : rh) + 1;
}
node* newNode(int key)
{
        node *entry = malloc(sizeof(node));
        if (!entry)
                return NULL;
        entry->data = key;
        entry->left = NULL;
        entry->right = NULL;
}
void print_level(node *head, unsigned int lvl)
{
        int j;
        if (head == NULL)
                return;
        if (lvl == 1)
                printf("[%u]", head->data);
        print_level(head->left, lvl - 1);
        print_level(head->right, lvl - 1);
}
void bfs(node *head)
{
        int h = height(head);
        int i;
        for (i = 1;i <= h; i++) {
                print_level(head, i);
                printf("\n");
        }
        return;
}
int main()
{
        node *n = newNode(10);
        n->left = newNode(20);
        n->right = newNode(30);
        n->left->left = newNode(40);
        n->left->right = newNode(50);
        n->right->left = newNode(60);
        n->right->right = newNode(70);
        bfs(n);
        return 0;
}
