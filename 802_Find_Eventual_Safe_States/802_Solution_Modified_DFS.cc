/* 
Algorithm:
    1.  Do DFS for each node and do DFS recursively for all its neighbors,
        if all its neighbors lead to safe state, mark this node as safe.
    2.  We optimise the DFS by caching the results of each node in color code array.
        Initially all nodes are set with color code 0.
            code 0 -> Not visited.
            code 1 -> visited and not safe state.
            code 2 -> visited and safe state.
    3.  We do DFS for neighbor only if they are not visited. If one of the neighbor
        is not safe, we mark this node as not safe and return.
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        vector<int> result;
        
        for(int i = 0; i < graph.size(); i++)
            if(dfs(i, color, graph))
                result.push_back(i);
        
        return result;
    }
    
    bool dfs(int node, vector<int>&color, vector<vector<int>>& graph)
    {
        if(color[node] > 0)
            return color[node] == 2;
        
        color[node] = 1;
        for(int neigh : graph[node])
        {
            if(color[neigh] == 2)
                continue;
            if(color[neigh] == 1 || dfs(neigh, color, graph) == false)
                return false;
        }
        // All paths lead to safe state
        color[node] = 2;
        return true;
    }
};