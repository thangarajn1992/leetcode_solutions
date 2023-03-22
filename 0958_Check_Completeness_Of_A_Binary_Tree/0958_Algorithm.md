# Algorithm
## Breadth First Search Approach

* By the definition of complete binary tree, there is no node to the right of the first null node and no node at a greater level than the first null node
* If we traverse the tree level by level from left to right and we come across a null node, all subsequent nodes in  the traversal should be null as well.
* No null node in between two non-null nodes

[Solution](https://github.com/thangarajn1992/leetcode_solutions/blob/main/0958_Check_Completeness_Of_A_Binary_Tree/0958_Solution_BFS.cc)

## Depth First Search Approach

* A complete binary tree can be represented with an array. 
* If index of node is i, then left child is at 2*i + 1 and right child is at 2*i + 2.
* If there are total of n nodes in complete binary tree, it can be represented with an array where nodes are ordered level by level, left to right
* Starting with root node at index 0, if the index of a node is greater than or equal to n, it
means a node is missing from the first n indices.

![Explanation1](https://github.com/thangarajn1992/leetcode_solutions/blob/main/0958_Check_Completeness_Of_A_Binary_Tree/0958_dfs_algo1.png)

[Solution](https://github.com/thangarajn1992/leetcode_solutions/blob/main/0958_Check_Completeness_Of_A_Binary_Tree/0958_Solution_BFS.cc)

