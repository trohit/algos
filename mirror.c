/* 
 * Program to mirror a binary tree
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
        int info;
        struct node *left, *right;
} node;

node *newNode(int key)
{
        node *entry = malloc(sizeof(node));
        entry->info = key;
        entry->right = entry->left = NULL;
        return entry;
}

void mirror(node *n)
{
        if (!n) return;
        node *t = n->left;
        n->left = n->right;
        n->right = t;
        mirror(n->left);
        mirror(n->right);
}
void preorder(node *h)
{
        if (h == NULL) return;
        printf("%u ", h->info);
        preorder(h->left);
        preorder(h->right);
}
 /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50

            30
           /  \
         40   20
        /    /  \
       50   25  10

     30 40 50 20 25 10

*/
int main()
{
        node *h = newNode(30);
        h->left = newNode(20);
        h->left->left = newNode(10);
        h->left->right = newNode(25);

        h->right = newNode(40);
        h->right->right = newNode(50);

        mirror(h);
        preorder(h);

        return 0;
}
