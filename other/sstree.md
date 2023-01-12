<h3 align="center">SS-Tree</h3>

`SS-Tree` or **Similarity Search Tree** is a dynamic structure for similarity indexing.
> The goal of similarity indexing is to facilitate efficient similarity queries of a dataset
typically [high dimensional feature vectors](https://mathinsight.org/vectors_arbitrary_dimensions).
**Similarity Queries** are queries that are related to some measure of similarity between
feature vector.

> The primary goal of similarity indexing is the same as the other indexing methods: to minimize 
average and worst case time required for query operations.

### [What is a Query](https://www.hostinger.com/tutorials/what-is-a-query)

> A database query is a request for data from a database. 
The request should come in a database table or a combination of tables using a code known as the query language. 

### Similarity

> we usually speak of dissimilarity or distance between featyre vectors
rather than similarity. The distance measure is a **weighted Euclidean distance metric**. Author has chosen this for efficiency reasons.

<p style="text-align: center" align="center">
  <img src="https://latex.codecogs.com/svg.image?D(X,Y)%20=%20%5Csqrt%7B(x,y)%5ET%20%5Ctextbf%7Bdiag(w)%7D%5Ctextbf%7B(x-y)%7D%7D">
</p>

> `x` and `y` are the feature vector being compared, 
and `w` is a vector representing the relative weight of 
each dimension for distance. Every element of `w` must 
be nonnegative.


### References

- D. A. White and R. Jain, "Similarity indexing with the SS-tree,"
Proceedings of the Twelfth International Conference on Data Engineering, 
New Orleans, LA, USA, 1996, pp. 516-523, doi: 10.1109/ICDE.1996.492202.
- [What is a Query](https://www.hostinger.com/tutorials/what-is-a-query)
