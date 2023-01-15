/*
Algorithm:
    1. Make the richer guy point to the lower guy.
    2. The Richest guy will have 0 in-degree.
    3. Use Topological sort (Kahn's Algorithm) to calculate the quietest person for each guy starting from the richest one.
*/
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
   vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
       int N = quiet.size();
       vector<int> answer(N, -1);
       vector<vector<int>> adj(N);
       vector<int> indegree(N, 0);
       queue<int> q;

       // Populate adj matrix (rich -> poor)
       for(vector<int> &richness : richer)
       {
           int rich = richness[0], poor = richness[1];
           adj[rich].push_back(poor);
           indegree[poor]++;
       }

       for(int person = 0; person < N; person++)
       {
           // Initially quieter person is themselves
           answer[person] = person;

           // push guys with 0 indegree in the queue
           if(indegree[person] == 0)
               q.push(person);
       }

       while(q.empty() == false)
       {
           int rich = q.front(); q.pop();

           // Check his poor neighbors, and if this rich
           // guy is the quietest for them.
           for(int &poor : adj[rich])
           {
               if(quiet[answer[poor]] > quiet[answer[rich]])
               {
                   answer[poor] = answer[rich];
               }
               indegree[poor]--;
               if(indegree[poor] == 0)
                   q.push(poor);
           }
       }

       return answer;
   }
};