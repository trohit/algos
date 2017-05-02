/*
 * Traversal routines for Binary Trees.
 */
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include "btree.h"
node *head = NULL;
node *newNode(int key)
{
        node *entry = malloc(sizeof(node));
        entry->info = key;
        entry->left = entry->right = NULL;
        return entry;
}
node *insert(node *head, int key)
{
        node *tmp = head;
        node *tmp2 = tmp;
        node *entry = head;
        bool isLeft = true;

        while(tmp != NULL) {
                if (key > tmp->info) {
                        tmp2 = tmp;
                        tmp = tmp->right;
                        isLeft = false;
                } else {
                        tmp2 = tmp;
                        tmp = tmp->left;
                        isLeft = true;
                }
        }

        // alloc mem for the new node
        entry = newNode(key);
        if (!entry) {
                // TODO: handle no mem case
                return head;
        } else if (!tmp2) {
                return entry;
        } else {
                if (isLeft) {
                        tmp2->left = entry;
                } else {
                        tmp2->right = entry;
                }
        }
        return head;
}
void preorder(node *head)
{
        if (!head) {
                return;
        }
        printf("%u ", head->info);
        preorder(head->left);
        preorder(head->right);
}
void inorder(node *head)
{
        if (!head) {
                return;
        }
        preorder(head->left);
        printf("%u ", head->info);
        preorder(head->right);
}
void postorder(node *head)
{
        if (!head) {
                return;
        }
        preorder(head->left);
        preorder(head->right);
        printf("%u ", head->info);
}
int max(int a, int b)
{
        if (a > b) {
                return a;
        }
        return b;
}
int height(node *head)
{
        if (head == NULL) {
                return 0;
        }
        if (head->left == NULL && head->right == NULL) {
                return 1;
        }
        return (1+ (max(height(head->left), height(head->right))));
}

/* 
 * Tries to pretty print the binary tree.
 * Is buggy and its still a work-in-progress.
 */
void printLevel_pretty(node *head, unsigned int lvl, unsigned int origlvl)
{
        int j;
        char spacer = ' ';
        int spaces_needed = 0;
        int buffer = 0;
        int isfirst = 1;
        if (head == NULL) {
                return;
        }
        if (lvl == 1) {
                spaces_needed = origlvl * 2;
                if (isfirst) {
                        buffer = 2;
                        isfirst = 0;
                } else {
                        buffer = 0;
                }

                for (j = 0; j < spaces_needed + buffer; j++)
                        printf("%c", spacer);
                printf("%u", head->info);
        }
        origlvl = origlvl / 2;
        printLevel_pretty(head->left, lvl - 1, origlvl);
        printLevel_pretty(head->right, lvl - 1, origlvl);
}
