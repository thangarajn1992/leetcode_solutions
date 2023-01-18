# 310 Minimum Height Trees Algorithm
## Topological Sort Approach
We can use kahn’s topological sort along with few properties specific to tree.
The distance between two nodes is the number of edges that connect the two nodes. The height of a tree can be defined as the maximum distance between the root and all its leaf nodes. If we view the graph as an area of a circle, and the leaf nodes as the peripheral of the circle, then what we are looking for are actually the centroids of the circle, i.e. nodes that is close to all the peripheral nodes (leaf nodes).

![Algo1](https://github.com/thangarajn1992/leetcode_solutions/blob/main/310_Minimum_Height_Trees/310_algo_pic1.png)

It is clear that the node with the value 1 is the centroid of the graph. If we pick the node 1 as the root to form a tree, we would obtain a tree with the minimum height, compared to other trees that are formed with any other nodes.
Before we proceed, here we make one assertion which is essential to the algorithm.
For the tree-alike graph, the number of centroids is no more than 2.
If the nodes form a chain, it is intuitive to see that the above statement holds, which can be broken into the following two cases:
If the number of nodes is even, then there would be two centroids.
If the number of nodes is odd, then there would be only one centroid.

![Algo2](https://github.com/thangarajn1992/leetcode_solutions/blob/main/310_Minimum_Height_Trees/310_algo_pic2.png)

For the rest of the cases, we could prove by contradiction. Suppose that we have 3 centroids in the graph, if we remove all the non-centroid nodes in the graph, then the 3 centroids nodes must form a triangle shape, as follows:

![Algo3](https://github.com/thangarajn1992/leetcode_solutions/blob/main/310_Minimum_Height_Trees/310_algo_pic3.png)

Because these centroids are equally important to each other, and they should be equally close to each other as well. If any of the edges that are missing from the triangle, then the 3 centroids would be reduced down to a single centroid.
However, the triangle shape forms a cycle which contradicts the condition that there is no cycle in our tree-alike graph. Similarly, for any of the cases that have more than 2 centroids, they must form a cycle among the centroids, which contradicts our condition.
Therefore, there cannot be more than 2 centroids in a tree-alike graph.


![Algo4](https://github.com/thangarajn1992/leetcode_solutions/blob/main/310_Minimum_Height_Trees/310_algo_pic4.png)

At each iteration, remove the leaf node and then remove the edge that connects to this leaf node and find the next level of leaf nodes until we are left with only centroids.
