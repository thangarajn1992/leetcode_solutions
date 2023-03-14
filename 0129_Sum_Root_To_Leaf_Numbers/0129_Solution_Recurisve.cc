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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        findSum(root, 0, sum);
        return sum;
    }

    void findSum(TreeNode* root, int val, int &sum)
    {
        if(root == nullptr)
            return;
        
        val = (val * 10) + root->val;

        findSum(root->left, val, sum);
        findSum(root->right, val, sum);
                
        if(root->left == nullptr && root->right == nullptr)
            sum += val;
    }
};