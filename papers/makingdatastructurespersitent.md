<h3 align="center">Making Data Structures Persistent</h3>

> Data structure is peristent if it supports access to multiple versions; only partially persistent if it all the versions can be accessed but only the newest version can be modified, and fully persitent if every version can be accessed and modified.

Author defines a *linked data structure* to be a finite collection of *nodes* and each of these *nodes* contain "*data*" field and a pointer field. 

> If a *node* `x` contains a pointer to a *node* `y`, we call `y` a *sucessor* of `x` and `x` a *predecessor* of `y`.

> In a general linked data structure we allow two kinds of operations
>- *access operations* : An *access* operation consists of a sequence of *access* steps, which compute a set of *accessed nodes* by beginning with the empty set and adding nodes. The **time** of an **access operation** would be number of **access steps** performed. Example for *access operation* would be *search for an item in a binary tree*.
> - *update operations*:  Intermixed sequence of *access* steps and *update* steps. The *update* step changes the structure. The **total time** of an *update* operation is **total number** of **access** and **update steps**; the **update time** is the number of **update steps**.Example for *update operation* would be *insertion of a new item in a binary search tree*.

### Partial Persistence


### References

```bibtex
@inproceedings{10.1145/12130.12142,
author = {Driscoll, J R and Sarnak, N and Sleator, D D and Tarjan, R E},
title = {Making Data Structures Persistent},
year = {1986},
isbn = {0897911938},
publisher = {Association for Computing Machinery},
address = {New York, NY, USA},
url = {https://doi.org/10.1145/12130.12142},
doi = {10.1145/12130.12142},
booktitle = {Proceedings of the Eighteenth Annual ACM Symposium on Theory of Computing},
pages = {109–121},
numpages = {13},
location = {Berkeley, California, USA},
series = {STOC '86}
}
```