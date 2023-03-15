# 958 Check Completeness of a Binary Tree
## Problem Statement

Given the root of a binary tree, determine if it is a complete binary tree. In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2<sup>h</sup> nodes inclusive at the last level h.

**Constraints**

* The number of nodes in the tree is in the range [1, 100].
* 1 <= Node.val <= 1000

**Example1**

![Example1](https://github.com/thangarajn1992/leetcode_solutions/blob/main/0958_Check_Completeness_Of_A_Binary_Tree/0958_example1.png)

```text
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), 
and all nodes in the last level ({4, 5, 6}) are as far left as possible.
```

**Example2**

![Example2](https://github.com/thangarajn1992/leetcode_solutions/blob/main/0958_Check_Completeness_Of_A_Binary_Tree/0958_example2.png)

```text
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
```
