/*
Kahn's Topological Sort Approach:

Maintain the recipes that are dependent on each recipe. (adj)
Have a count of recipes each recipe depends on (indegree)
Do not include the items that are present in the supplies as part of dependencies since they are anyway available already.
Include recipes with indegree 0 into the queue. Keep popping the element from the queue and reduces their dependent recipes indegree. If any recipes indgree becomes 0, add it into the queue.
While popping the recipes from queue, add them into the result, since it is a possible recipe.
*/

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> adj; // dependents
        unordered_map<string, int> indegree; // No. of dependencies
        queue<string> q; // to do topological sort bfs

        set<string> supply(supplies.begin(), supplies.end());
        for(string &s : recipes)
            indegree[s] = 0;

        vector<string> possible_recipes; // result

        for(int r = 0; r < recipes.size(); r++)
        {
            for(string &ingredient : ingredients[r])
            {
                // if ingredient is present in supply, don't add as dependency
                if(supply.find(ingredient) == supply.end())
                {
                    adj[ingredient].push_back(recipes[r]);
                    indegree[recipes[r]]++;
                }
            }
        }
        
        for(auto recipe : indegree)
            if(recipe.second == 0)
                q.push(recipe.first);

        while(q.empty() == false)
        {
            string recipe = q.front(); q.pop();
            possible_recipes.push_back(recipe);

            for(auto dep : adj[recipe])
            {
                indegree[dep]--;
                if(indegree[dep] == 0)
                    q.push(dep);
            }
        }

        return possible_recipes;
    }
};