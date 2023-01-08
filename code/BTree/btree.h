/*
This file contains implementation 2-3 B-Tree (Order: 3)
- Every node has at most 3 children
*/
#ifndef BTREE_H
#define BTREE_H


#include <stdio.h>
#include <stdbool.h>

typedef struct node_ {
	int* keys; // pointer to the keys
	struct node_** childtree; // pointer to the child tree
	int n_key; // current number of keys
	bool isLeaf;
	int max_k; // maximum number of keys
} node;

typedef struct tree_ {
	node* rootnode;
	int height; 
} btree;


node* allocateNode(int k, int t) {
	/*summary: create a node in the heap
	args:
		int k -> value of the key
		int t -> maximum number of keys
	ret:
		node* -> pointer to the node
	*/
};


btree* createBTree() {
	/*summary: create a tree in the heap
	args:
	ret:
		btree* -> pointer to a btree
	*/
}

#endif // BTREE_H
