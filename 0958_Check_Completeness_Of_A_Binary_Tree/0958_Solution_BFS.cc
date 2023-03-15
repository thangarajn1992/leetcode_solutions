 /* BFS Approach */
/* 
   By the definition of complete binary tree, there is no node to the right of the first null node 
   and no node at a greater level than the first null node

   If we traverse the tree level by level from left to right and we come across a null node, 
   all subsequent nodes in  the traversal should be null as well.

   No null node in between two non-null nodes
*/

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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool nullNodeFound = false;

        while(q.empty() == false)
        {
            TreeNode* cur = q.front(); q.pop();

            if(cur == nullptr)
                nullNodeFound = true;
            else
            {
                if(nullNodeFound == true)
                    return false;
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        
        return true;
    }
};
