/* DFS Approach */
/*
    A complete binary tree can be represented with an array. 
    If index of node is i, then left child is at 2*i + 1 and right child is at 2*i + 2.
    If there are total of n nodes in complete binary tree, it can be represented with an
    array where nodes are ordered level by level, left to right

    Starting with root node at index 0, if the index of a node is greater than or equal to n, it
    means a node is missing from the first n indices.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        return findCompleteness(root, 0, countNodes(root));
    }

    int countNodes(TreeNode *root) {
        if(root == nullptr)
            return 0;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool findCompleteness(TreeNode *root, int index, int n)
    {
        if(root == nullptr)
            return true;
        
        if(index >= n)
            return false;
        
        return findCompleteness(root->left, 2*index + 1, n) &&
               findCompleteness(root->right, 2*index + 2, n);
    }
};
