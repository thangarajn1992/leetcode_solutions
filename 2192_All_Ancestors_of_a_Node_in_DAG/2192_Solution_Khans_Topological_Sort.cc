/* 
Kahn's Topological Sort Algorithm:
* Calculate in_degree of each node
* Have a array of set of integers to store ancestors for each node
* While doing BFS using queue, update its child ancestors with this node and its ancestors.
* Once BFS is done, populate result with the ancestor set we populated during BFS
*/
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> in_degree(n, 0);
        queue<int> q;
        vector<vector<int>> result(n);
        vector<set<int>> ancestors(n);

        for(vector<int> &edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            in_degree[edge[1]]++;
        }

        for(int i = 0; i < n; i++)
            if(in_degree[i] == 0)
                q.push(i);

        while(q.empty() == false)
        {
            int cur = q.front(); q.pop();

            for(int &child : adj[cur])
            {
                // inserting this node into ancestor list of its child
                ancestors[child].insert(cur);

                // inserting all cur's ancestors to child's ancestors
                for(int ancestor : ancestors[cur])
                    ancestors[child].insert(ancestor);
                
                in_degree[child]--;
                if(in_degree[child] == 0)
                    q.push(child);
            }
        }

        for(int i = 0 ; i < n; i++)
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        
        return result;
    }
};