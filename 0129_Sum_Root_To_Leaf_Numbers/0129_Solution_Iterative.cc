#include <queue>
using namespace std;

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
        int result = 0;
        queue<pair<int,TreeNode*>> q;

        q.push({0, root});

        while(q.empty() == false)
        {
            pair<int, TreeNode*> cur = q.front(); q.pop();

            int sum = (cur.first * 10) + cur.second->val;

            if(cur.second->left == nullptr && cur.second->right == nullptr)
            {
                result += sum;
            }
            else 
            {
                if(cur.second->left != nullptr)
                    q.push({sum, cur.second->left});
                if(cur.second->right != nullptr)
                    q.push({sum, cur.second->right});
            }
        }

        return result;
    }
};