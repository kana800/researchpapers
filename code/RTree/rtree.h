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
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct rect_ {
	double x0;
	double x1;
	double y0;
	double y1;
	double area; // stores the area
} rect;

typedef struct node_ node;

typedef struct nodeentry_ {
	node** ptr;
	int count;
	bool isFull;
}childpointer;

typedef struct node_ {
	char repr; // character to represent the node
	bool leaf; // is it a leaf node
	struct childpointer* arr; // holds the child pointers
	struct rect_* rect; // rectangle that contain all the child pointers
} node;

typedef struct r_tree {
	int height; // height of the tree
	node* rootnode; // pointer to root node
} rtree;

rect* createBoundingBoxes(double x0, double y0, double x1, double y1) {
	/*summary: create a rectangle in the heap
	args:
		double x0, y0 -> coordinate points [point 1]
		double x1, y1 -> coordinate points [point 2]
	ret:
		rect -> pointer to a rectangle
	*/
	rect* t = malloc(sizeof(rect));
	t->x0 = x0;
	t->y0 = y0;
	t->x1 = x1;
	t->y1 = y1;
	// calculating the area of the tuple;
	t->area =  (x1 - x0) * (y1 - y0);
	return t;
}

childpointer* createChildPointerArray() {
	/*summary: creates a child pointer array in the heap
	note:
		maximum number of items in a array would be M; which
		is 2
	ret:
		childpointer* -> pointer to childpointer array
	*/
	childpointer* cparr = malloc(sizeof(cparr));
	node* n = malloc(sizeof(node) * 2);
	cparr->ptr = n;
	cparr->count = 0;
	cparr->isFull = false;
	return cparr;
}

bool addChildPointer(childpointer* arr, node* n) {
	/*summary: add node to childpointer arr
	args:
		childpointer* arr -> pointer to the array
		node* n -> pointer to the node
	ret:
		true -> success
		false -> fail
	possible reasons for fail;
		array is full
	*/
	int currcount = arr->count;
	if (currcount > 1) {
		fprintf(stderr, "child pointer array is full\n");
		arr->isFull = true;
		return false;
	}
	arr->ptr[currcount] = n;
	arr->count++;
	return true;
}

node* createNode(char repr, bool leaf, ...) {
	/*summary: create a node in the heap
	args:
		char* repr -> representation character of the node
		bool leaf -> is the node a leaf
	optional args:
			rect* -> pointer to a rect
			node* -> pointer for the child pointer
	ret:
		node* -> pointer to a node
	*/
	node* n = malloc(sizeof(node));
	n->repr = repr;
	// obtaining rect value
	va_list parameters;
	va_start(parameters, leaf);
	if (leaf) {
		n->rect = va_arg(parameters, struct rect_ *);
		va_end(parameters);
		// no child pointer for leaf node
		n->arr = NULL;
		n->leaf = true;
	}
	else {
		n->arr = createChildPointerArray();
		node* tempnode = va_arg(parameters, struct node_ *);
		addChildPointer(n->arr, tempnode);
		n->rect = tempnode->rect;
		n->leaf = false;
		va_end(parameters);
	}
	return n;
}

rtree* createRTree() {
	/*summary: creates a r-tree in the heap; since the dimension is 2 
	this function doesnt much of use but we are going to use it anyways
	ret:
		rtree* -> pointer to a rtree
	*/
	rtree* r = malloc(sizeof(rtree));
	r->height = 0;
	r->rootnode = createNode('a',true);
	return r;
}

void freeNode(node* n) {
	/*summary: release the node from the memory
	args:
		node* n -> pointer to the ndoe;
	*/
	free(n->rect);
	n->rect = NULL;
	childpointer* tempcp = n->arr;
	free(tempcp->ptr);
	free(tempcp->count);
	free(n);
}

void freeTree(rtree* r) {
	/*summary: release the tree from the memory
	args:
		rtree* r -> pointer to a rtree
	*/
	free(r);
}

rect* doesItHaveBiggerArea(node* n, rect* r1) {
	/*summary: compares two tuples together;
	args:
		tuple* t1
		tuple* t2
	ret:
		t1 > t2 : 1
		t1 == t2 : 0
		t1 < t2 : -1
	*/
}

node* getBiggestChildNode(childpointer* cp) {
	/*summary: return the biggest node in the
	childpointer
	args:
		childpointer* cp -> pointer childpointer array
	ret:
		node * -> pointer to a node
	*/

	// if not full; return the
	// first node
	if (!cp->isFull) {
		return cp->ptr[0];
	}
	return cp->ptr[0] > cp->ptr[1] 
		? cp->ptr[0] : cp->ptr[1];
}

void adjustNodeSize(node* n) {
	/*summary: Adjust the size of the node
	args:
		node* n -> pointer to a node
	*/
	// checking if the current rect
	// is already big enough
	node* tempNode = getBiggestChildNode(n->arr);
	if (n->rect->area 
		<= tempNode->rect->area) {
		n->rect = tempNode;
		return;
	} 
	return;
}

void insert(rtree* r, char* repr, rect* rect) {
	/*summary: inserts the node to the tree structure
	args:
		rtree* r -> rtree
		char* repr -> representation of the node
		rect* rect -> rectangle
	*/

	// no root nodes present is rtree
	if (r->rootnode == NULL) {
		// rect will be added as the child pointer in
		// to the rtree and the rect in node will be
		// pointed to the rect
		r->rootnode = createNode(repr, false, rect);
		return;
	}

	node* tempNode = r->rootnode;
	// traversing the child pointers 
	while (tempNode->arr != NULL) {
		childpointer* tempcp = tempNode->arr;
		if (!tempcp->isFull) {
		// not full; add it to the child pointer and
		// adjust the node's rect
			addChildPointer(tempcp, tempNode);

		}
	}

}


#endif // !RTREE
