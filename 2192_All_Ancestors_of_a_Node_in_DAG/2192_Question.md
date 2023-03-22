# 2192 All Ancestors of a Node in Directed Acyclic Graph
## Problem Statement
You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.

**Constraints**:

* 1 <= n <= 1000
* 0 <= edges.length <= min(2000, n * (n - 1) / 2)
* edges[i].length == 2
* 0 <= fromi, toi <= n - 1
* from<sub>i</sub> != to<sub>i</sub>
* There are no duplicate edges.
* The graph is directed and acyclic.

Example 1:

![Example1](https://github.com/thangarajn1992/leetcode_solutions/blob/main/2192_All_Ancestors_of_a_Node_in_DAG/2192_picture1.png)

```text
Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.
```

Example 2:

![Example2](https://github.com/thangarajn1992/leetcode_solutions/blob/main/2192_All_Ancestors_of_a_Node_in_DAG/2192_picture2.png)

```text
Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Node 0 does not have any ancestor.
- Node 1 has one ancestor 0.
- Node 2 has two ancestors 0 and 1.
- Node 3 has three ancestors 0, 1, and 2.
- Node 4 has four ancestors 0, 1, 2, and 3.
```
 

##Solution

### Kahn's Topological Sort Algorithm

* Calculate in_degree of each node
* Have a array of set of integers to store ancestors for each node
* While doing BFS using queue, update its child ancestors with this node and its ancestors.
* Once BFS is done, populate result with the ancestor set we populated during BFS


```c++  
#include <vector>
#include <queue>
#include <set>

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
                ancestors[child].insert(ancestors[cur].begin(), ancestors[cur].end());
                
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
```