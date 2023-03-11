#include <vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        queue<int> leaves;
        vector<int> ans;
        int remaining_nodes = n;

        for(vector<int> edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            // indegree is used instead of adj[].size(), to avoid
            // removal of edges from set during each iteration in BFS
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        for(int node = 0; node < n; node++)
        {
            // leaf nodes will have indegree of 1
            // Special case: when only one node is present, indegree will 0.
            if(indegree[node] <= 1) 
                leaves.push(node);
        }

        // For non-cyclic graph(tree), we need to find the centroid nodes that
        // are closer to all the leaf nodes (min height).
        // since having 3 or more centroids will cause a cycle, 
        // we can have maximum of 2 centroids.

        // At each iteration, remove the leaf node and the remove the edge
        // that connects to this leaf node and find next level of leaf nodes
        // until we are left with only centroids.
        while(leaves.empty() == false && remaining_nodes > 2)
        {
            remaining_nodes -= leaves.size();
            int size = leaves.size();
            while(size > 0)
            {
                int leaf = leaves.front(); leaves.pop();
                for(auto neigh: adj[leaf])
                {
                    indegree[neigh]--;
                    if(indegree[neigh] == 1)
                        leaves.push(neigh);
                }
                size--;
            }
        }

        while(leaves.empty() == 0)
        {
            ans.push_back(leaves.front());
            leaves.pop();
        }
        
        return ans;
    }
};