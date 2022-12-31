### What is an R-Tree?

> Its a dynamic index structure for spatial searching; *spatial-data* are objects that covers areas in multi-dimensional spaces. They can not be well represented by point locations.

> **R-Tree is a height balanced tree with index records in its leaf nodes (containting pointers to data objects)**

### R-Tree Index Structure

> A spatial database consists of a collection of tuples representing spatial objects.

The *leaf nodes* consist of 
```
(I, tuple-identifier)
I = (I0,I1,...,In)
```
- entry index `I`: minimum bounding rectangle, `I`
    - `n` is the number of dimensions
    - `I0` would be `1` dimension; `I1` would be `[a,b]` a close bounded interval, that describes the extent of the object.

- tuple-identifier

Example:
```
(([1,2],[2,4]), L1)
```
The rectangle in the database will be identified as `L1`

The number of entries that fit in one node is maximum `M` and minimum `m` 
`m <= M/2`

The *non-leaf node* consist of 
```
(I, child-pointer)
```
- `I` is the smallest rectangle that spatially contains all the rectangles/entries in the child node
- child-pointer is the address of a lower node in the *R-Tree*

### Properties of an R-Tree

> 1. Every leaf node contains between `m` and `M` index records unless it is the root.
> 2. All leaf nodes are at the same level.
> 3. Every non-leaf node has between `m` and `M` unless it is the root.
> 4. For each entry `(I, child - pointer)` in a non-leaf node, `I` is the smallest rectangle spatially contains the rectangles in a child node.

### References

- [R-Tree by Vlan Ag](https://www.youtube.com/watch?v=Jd8F2hVnGtQ)
- [R-Tree Slides](https://www2.cs.sfu.ca/CourseCentral/454/jpei/slides/R-Tree.pdf)
- [RTree Wikipedia](https://en.wikipedia.org/wiki/R-tree)

