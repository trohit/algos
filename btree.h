#ifndef __BTREE_H__
#define __BTREE_H__
typedef struct _node {
	struct _node *right, *left;
	int info;
} node;
#endif /* __BTREE_H__ */
