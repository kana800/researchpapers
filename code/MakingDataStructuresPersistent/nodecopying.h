/*
This file contains an implementation of node-copying
from the paper making data structures persistent
*/
#ifndef NODECOPYING_H
#define NODECOPYING_H

int d = 5; // maximum number of pointers in an ephemeral node
int p = 5; // maximum number of predecessors of an ephemeral node


typedef struct ephnode {
	// information fields
	float data; // data point
	int version; // version of structure
} ephemeralnode;

typedef struct pernode {
	// information fields
	float data;
	int eph_version;
	int per_version;
	// pointer information
	ephemeralnode* orgpointer[d]; // contains original pointers
	ephemeralnode* prepointer[p]; // contains predecessor pointers
} persistentnode;

typedef struct ephstruct {
	ephemeralnode* node;
	persistentnode* family[p];
} ephemeralstruct;

typedef struct perstruct {
	persistentnode* node;
	persistentnode* nextnode;
} persistentstruct;


#endif // !NODECOPYING_H
