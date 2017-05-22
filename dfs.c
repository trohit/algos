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

void pre_order(node *head)
{
	if (head == NULL) return;
	printf("%u ", head->data);
	pre_order(head->left);
	pre_order(head->right);
}

void in_order(node *head)
{
	if (head == NULL) return;
	in_order(head->left);
	printf("%u ", head->data);
	in_order(head->right);
}

void post_order(node *head)
{
	if (head == NULL) return;
	post_order(head->left);
	post_order(head->right);
	printf("%u ", head->data);
}
/*
 *             10
 *          /     \
 *        20       30
 *       /  \     /   \
 *     40    50 60    70
 *          /
 *        80
 *
 * DFS
 * Preorder: (root, left, right)
 * 10 20 40 50 80 30 60 70
 *
 * Inorder: (left, root, right)
 * 40 20 80 50 10 60 30 70
 *
 * Postorder: (left, right, root)
 * 40 80 50 20 60 70 30 10
 */
void foo()
{
        node *n = newNode(10);
        n->left = newNode(20);
        n->right = newNode(30);
        n->left->left = newNode(40);
        n->left->right = newNode(50);
        n->right->left = newNode(60);
        n->right->right = newNode(70);
        n->left->right->left = newNode(80);
        bfs(n);
	pre_order(n);
	in_order(n);
	post_order(n);
}
/*
 *             50
 *          /     \
 *        20       70
 *       /  \     /   \
 *     10    40 60    80
 *          /
 *        30
 *
 * DFS
 * Preorder: (root, left, right)
 * 50 20 10 40 30 70 60 80
 *
 * Inorder: (left, root, right)
 * 10 20 30 40 50 60 70 80
 *
 * Postorder: (left, right, root)
 * 10 30 40 20 60 80 70 50
 */        
void bar()
{
        node *n = newNode(50);
        n->left = newNode(20);
        n->left->left = newNode(10);
        n->left->right = newNode(40);
        n->left->right->left = newNode(30);
        n->right = newNode(70);
        n->right->left = newNode(60);
        n->right->right = newNode(80);
        bfs(n);
	pre_order(n);
	printf("\n");
	in_order(n);
	printf("\n");
	post_order(n);
}
int main()
{
	bar();
	return 0;
}
