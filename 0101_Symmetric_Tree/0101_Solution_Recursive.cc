
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
    bool isSymmetric(TreeNode* root) {
        return isSymmetricUtil(root->left, root->right);
    }
    
    bool isSymmetricUtil(TreeNode *node1, TreeNode *node2)
    {
        if(node1 == nullptr && node2 == nullptr)
            return true;
        
        return node1 != nullptr && 
               node2 != nullptr &&
               node1->val == node2->val &&
               isSymmetricUtil(node1->left, node2->right) &&
               isSymmetricUtil(node1->right, node2->left);
    }
};