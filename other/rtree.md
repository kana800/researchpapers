### What is an R-Tree?

> Its a dynamic index structure for spatial searching; *spatial-data* are objects that covers areas in multi-dimensional spaces. They can not be well represented by point locations.

> **R-Tree is a height balanced tree with index records in its leaf nodes (containting pointers to data objects)**

### R-Tree Index Structure

> A spatial database consists of a collection of tuples representing spatial objects.

The *leaf nodes* consist of: 
```
(I, tuple-identifier)
I = (I0,I1,...,In)
```
- entry index `I`: minimum bounding rectangle, `I`
    - `n` is the number of dimensions
    - `I0` would be `1` dimension; `I1` would be `[a,b]` a close bounded interval, that describes the extent of the object.

- tuple-identifier

The *non-leaf node* consist of: 
```
(I, child-pointer)
```
- `I` is the smallest rectangle that spatially contains all the rectangles/entries in the child node
- child-pointer is the address of a lower node in the *R-Tree*

Example:
```
(([1,2],[2,4]), L1)
```
The rectangle in the database will be identified as `L1`

The number of entries that fit in one node is maximum `M` and minimum `m`(`m <= M/2`).

### Properties of an R-Tree

> 1. Every leaf node contains between `m` and `M` index records unless it is the root.
> 2. All leaf nodes are at the same level.
> 3. Every non-leaf node has between `m` and `M` unless it is the root.
> 4. For each entry `(I, child-pointer)` in a non-leaf node, `I` is the smallest rectangle spatially contains the rectangles in a child node.


### Implementation of R-Tree

<p align="center"> <a href=""> Implementation On R-Tree </a></p>

#### Object Creation

> Our R-Tree **consists of nodes which we'll be able to divide into leaves (containing key-value entries)** and 
branches containing many children - be it leaves or other branches.

Also we will be adding boolean value called `leaf` that will tell us whether `node` is a `leaf` or not. 

> while only leaf nodes contain the values, keys are present in both leaves and branches. 
However, branch keys (for our 2 dimensional space represented by rectangles) are describing so called 
**minimum bounding rectangle** (MBR) which is sufficient to cover all of the children keys stored 
within that parent.

```c
typedef struct node_ {
	char repr; // character representation of the node (tuple-identifier)
	bool leaf; // is it a leaf node
	struct rect_* rect; // rectangle that spatially contains all the entries;
	struct nodeentry_* childpointer; // holds the child pointers	
} node;
```

 - `struct rect_* rect` is the pointer that holds the `rect` object that spatially contains all the entries/child pointers;
```c
typedef struct rect_{
	double x0;
	double x1;
	double y0;
	double y1;
	double area;
}rect;
```
 - `struct nodeentry_* childpointer` contains pointer to the children nodes;

 ```c
 typedef struct nodeentry_ {
	node* ptr;
	node* nextchild;
}childpointer;
 ```

`r_tree` structure will data related to the tree data structure; `rootnode` will hold starting node;

```c
typedef struct r_tree {
	int height; // tracks the height of the tree
	node* rootnode; // pointer to root node
} rtree;
```

#### Insertion

When inserting a `node` we need to find smallest rectangle for the object.


### References

- [R-Tree by Vlan Ag](https://www.youtube.com/watch?v=Jd8F2hVnGtQ)
- [R-Tree Slides](https://www2.cs.sfu.ca/CourseCentral/454/jpei/slides/R-Tree.pdf)
- [RTree Wikipedia](https://en.wikipedia.org/wiki/R-tree)
- [Implementation on R-Tree](https://github.com/tidwall/rtree.c/blob/master/rtree.c)
- [Blog about R-Tree](https://bartoszsypytkowski.com/r-tree/)
