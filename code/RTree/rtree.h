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

typedef struct rect_ {
	double x0;
	double x1;
	double y0;
	double y1;
	double area; // stores the area
} rect;

typedef struct node_ {
	char repr; // character to represent the node
	int full;
	struct rect_* rect_1; // stores the rectangle# 1
	struct rect_* rect_2; // stores the rectangle# 2
	bool leaf; // leaf node status
} node;

typedef struct r_tree {
	int height; // height of the tree
	node* rootnode; // pointer to root node
} rtree;

rect* createBoundingBoxes(
	double x0, double y0, double x1, double y1) {
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

node* createNode(char repr, bool leaf) {
	/*summary: create a node in the heap
	args:
		char* repr -> representation character of the node
		bool leaf -> is the node a leaf
	ret:
		node* -> pointer to a node
	*/
	node* n = malloc(sizeof(node));
	n->repr = repr;
	n->full = false;
	n->rect_1 = NULL;
	n->rect_2 = NULL;
	n->leaf = leaf;
	return n;
}

int addRectToNode(node* n,rect* rect) {
	/*summary: add a rectangle to the node
	args:
		node* n -> pointer to the node
		rect* rect -> pointer to a rectangle
	ret:
		1 -> success
		-1 -> failed
	*/
	if (n->full) {
		// need to split the rect here
		// will implement later
		return -1;
	}
	if (n->rect_1 == NULL) n->rect_1 = rect;
	else {
		n->rect_2 = rect;
		n->full = true;
		n->leaf = false;
	}
	return 1;
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
	rect* tr1 = n->rect_1;
	rect* tr2 = n->rect_2;
	n->rect_1 = NULL;
	n->rect_2 = NULL;
	if (n->leaf) free(tr1);
	else {
		free(tr1);
		free(tr2);
	}
	free(n);
}

void freeTree(rtree* r) {
	/*summary: release the tree from the memory
	args:
		rtree* r -> pointer to a rtree
	*/
	free(r);
}

int doesItHaveBiggerArea(node* n, rect* r1) {
	/*summary: HELPER
	compares two tuples together;
	t1 against t2;
	args:
		tuple* t1
		tuple* t2
	ret:
		t1 > t2 : 1
		t1 == t2 : 0
		t1 < t2 : -1
	*/
}

void insert(rtree* r, rect* rect) {
	/*summary: inserts the node to the tree structure
	args:
		rtree* r -> rtree
		rect* rect -> rectangle
	*/

	// no root nodes present is rtree
	// or rtree rootnode is a leaf
	if (r->rootnode->leaf) {
		int ret = addRectToNode(r->rootnode, rect);
	}

}


#endif // !RTREE
