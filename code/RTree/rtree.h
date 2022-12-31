/*
This file contains an implementation for RTree
- Minimum number of nodes in a node (m) -> 1
- Maximum number of nodes in a node (M) -> 2
- The nodes will be 2D
- The minimum point and maximum point of rectangle will 
be stored in a tuple
*/
#ifndef RTREE_H
#define RTREE_H

#include <stdio.h>

typedef struct tuple_ {
	double x0;
	double x1;
	double y0;
	double y1;
} tuple;


typedef struct node_ {
	char repr; // character to represent the node
	tuple* tuple; // stores the content nodes
	struct node_* left; // left sub-tree
	struct node_* right; // right sub-tree
} node;

node* ROOTNODE = NULL; // stores the rootnode


#ifdef  DEBUG
void printTree(node* rootnode) {
#else
static void printTree(node* rootnode) {
#endif
	/*summary: print the tree
	args:
		node* rootnode -> pointer to a rootnode
	*/
	return;
}


tuple* createBoundingBoxes(
	double x0, double y0, double x1, double y1) {
	/*summary: create a tuple in the heap
	args:
		double x0, y0 -> coordinate points [point 1]
		double x1, y1 -> coordinate points [point 2]
	ret:
		tuple* -> pointer to a tuple 
	*/
	tuple* t = malloc(sizeof(tuple));
	t->x0 = x0;
	t->y0 = y0;
	t->x1 = x1;
	t->y1 = y1;
	return t;
}

node* createNode(char repr, tuple* tuple) {
	/*summary: create a node in the heap
	args:
		char* repr -> representation character of the node
		tuple* tuple -> pointer to the tuple; data of 2D rect
	ret:
		node* -> pointer to a node
	*/
	node* n = malloc(sizeof(node));
	n->repr = repr;
	n->tuple = tuple;
	n->left = NULL;
	n->right = NULL;
	return n;
}

int insert(node* root, char repr, tuple* tuple) {
	/*summary: inserts the node to the tree structure
	args:
		node* root -> root node
		char* repr -> representation character of the node
		tuple* tuple -> pointer to the tuple; data of 2D rect
	ret:
		1 -> Success
		-1 -> Fail
	*/
	if (ROOTNODE == NULL) {
		ROOTNODE = root;
		return 1;
	} 

	return -1;
}

node* searchByChar(node* root, char repr) {
	/*summary: search by character
	args:
		node* root -> root node
		char* repr -> representation character of the node
	ret:
		node* -> pointer to the node
	*/
}


node* searchByTuple(node* root, tuple* tuple) {
	/*summary: search by tuple
	args:
		node* root -> root node
		tuple* tuple -> pointer to the tuple; data of 2D rect
	ret:
		node* -> pointer to the node
	*/
}


#endif // !RTREE
