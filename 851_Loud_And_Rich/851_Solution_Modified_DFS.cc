/*
Algorithm:
    1. Make the poor point to the rich
    2. Do DFS for each node if their answer is not calculated yet.
    3. While doing DFS, do DFS iteratively for all its rich neighbors.
    4. Only after processing all its rich neighbors, Update the answer for this guy with quieter person among his rich neighbors
*/
#include <vector>
using namespace std;

class Solution {
public:
   vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
       int N = quiet.size();
       vector<int> answer(N, -1);
       vector<vector<int>> adj(N);
      
       for(vector<int> &richness : richer)
       {
           int rich = richness[0], poor = richness[1];
           adj[poor].push_back(rich);
       }

       for(int person = 0; person < N; person++)
           DFS_util(person, adj, quiet, answer);

       return answer;
   }

   void DFS_util(int person, vector<vector<int>>&adj, vector<int>&quiet,
                 vector<int> &answer)
   {
       if(answer[person] == -1)
       {
           answer[person] = person;
           for(int &rich : adj[person])
           {
               DFS_util(rich, adj, quiet, answer);
               if(quiet[answer[person]] > quiet[answer[rich]])
                   answer[person] = answer[rich];
           }
       }
   }
};