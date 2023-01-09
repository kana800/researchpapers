/*
This file contains implementation B-Tree (Order: 4)
- Every node has at most 4 children
- Every node has at most 3 keys
*/

#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DEFAULT_ORDER 4


typedef struct node_ {
	int* keys; // pointer to the keys
	struct node_** childtree; // pointer to the child tree
	int n_key; // current number of keys
	bool isLeaf; // leaf node or not
} node;

typedef struct tree_ {
	node* rootnode; // pointer to the rootnode
	int height; // height of the tree 
	int order;  // order of the tree
	int max_keys; // maximum number of keys
	int max_child; // maximum number of children
} btree;

node* allocateNode(int nk, int mk ,bool leaf) {
	/*summary: create a node in the heap
	args:
		int nk -> max number of keys in the node
		int mk -> max number of child node in the node 
		bool leaf -> is it a leaf node ? 
	ret:
		node* -> pointer to the node
	*/
	node* temp = malloc(sizeof(node));
	temp->keys = malloc(sizeof(int)* nk);
	temp->childtree = malloc(sizeof(node*) * mk);
	temp->n_key = 0;
	temp->isLeaf = leaf;
	return temp;
};

btree* createBTree(int order) {
	/*summary: create a tree in the heap
	args:
		int order -> minimum order of the btree
	ret:
		btree* -> pointer to a btree
	*/
	btree* temptree = malloc(sizeof(btree));
	temptree->rootnode = NULL;
#ifdef DEFAULT_ORDER
	temptree->order = DEFAULT_ORDER;
#else
	temptree->order = order;
#endif
	temptree->height = 0;
	temptree->max_keys = temptree->order - 1;
	temptree->max_child = temptree->order;
	return temptree;
}

void freeTree(btree* t) {
	/*summary: free the tree from the heap
	args:
		btree* t -> pointer to a btree
	*/
}

void printBTree(btree* t) {
	/*summary: traverse and print btree
	args:
		btree* t -> pointer to a btree
	*/
}

void splitChildTree(int i, node* n) {
	/*summary: split the child tree 
	args:
		int i -> split point 
		node* n -> node to be spilt
	*/

	// cut the node in half and copy the first half of the
	// keys to the new node
	// if node isnt a leaf; copy the child pointers to the 
	// new node
	node* tempnode = allocateNode(n->n_key, n->n_key + 1, n->isLeaf);
	// if odd leaves a decimal point;;
	tempnode->n_key = n->n_key / 2;
	int halfed = n->n_key / 2;

	// copy over the right half of the old node into the
	// new node
	for (int j = 0; j < n->n_key; j++ ) {
		tempnode->keys[j] = n->keys[j + halfed];
	}

	// copy the child pointer if the node is a leafnode
	if (!n->isLeaf) {
		for (int j = 0; j < n->n_key + 1; j++) {
			tempnode->childtree[j] = n->childtree[j + halfed];
		}
	}

	n->n_key = halfed;


}

void insertNode(btree* t, int k) {
	/*summary: insert key to the tree
	args:
		btree* t -> pointer to a btree
		int k -> key value
	*/

	// empty tree
	if (t->rootnode == NULL) {
		t->rootnode = allocateNode(t->max_keys, t->max_child, true);
		t->rootnode->keys[0] = k;
		// increase the key value
		t->rootnode->n_key = 1;
	}
	else {
		if (t->rootnode->n_key == t->max_keys) {
		// checking whether the node is full; if true 
		// increase the height of the tree
		// 1.create new node
		// 2.new node child is old root node
		// 3.split the old root node and move keys accordingly  
			node* tempnode = allocateNode(t->max_keys, t->max_child, false);
			tempnode->childtree[0] = t->rootnode;
		}{

		}
	}

}

#endif // BTREE_H
