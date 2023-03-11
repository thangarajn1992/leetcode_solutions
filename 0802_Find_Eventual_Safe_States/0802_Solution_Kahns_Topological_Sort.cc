/* Kahn's Topological Sort Approach */
/*
1. Create a list of incoming edges for each node. 
2. Insert all the nodes with 0 outgoing edges (safe state) into the queue.
3. Do BFS using queue, mark node as safe and reduce the outgoing for their neighbors
4. If any of the neighbor outgoing edges become 0, add it to the queue.
*/
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> incoming_neighbors(V);
        vector<int> outgoing_edges(V);
        vector<bool> is_safe(V, false);
        vector<int> result;
        queue<int> q;

        for(int u = 0; u < V; u++){
            for(int &v: graph[u])
                incoming_neighbors[v].push_back(u);

            outgoing_edges[u] = graph[u].size();
            if(outgoing_edges[u] == 0)
                q.push(u);
        }

        while(q.empty() == false)
        {
            int v = q.front(); q.pop();
            is_safe[v] = true;
             for(int &u : incoming_neighbors[v])
            {
                outgoing_edges[u]--;
                if(outgoing_edges[u] == 0)
                    q.push(u);
            }
        }

        for(int i = 0; i < V; i++)
            if(is_safe[i] == true)
                result.push_back(i);
        
        return result;
    }
};