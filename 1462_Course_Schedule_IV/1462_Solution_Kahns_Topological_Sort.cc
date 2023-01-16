/* Kahn's Topological Sort Approach */
/*
Calculate in_degree of each course (depended_on)
Have a array of set of integers to store depends_on for each course 
While doing BFS using queue, update its child depends_on with this course and its depends_on set.
Once BFS is done, check each query and whether query[1] is present in query[0] depends_on set.
*/

#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // courses that depends on this course to be completed
        vector<vector<int>> dependents(numCourses);
        // No. of courses this course depends on
        vector<int> depended_on(numCourses, 0);
        queue<int> q;
        // Set of courses that each course depends on directly or indirectly
        vector<set<int>> depends_on(numCourses);
        vector<bool> result;

        for(vector<int> &prerequisite : prerequisites)
        {
            dependents[prerequisite[1]].push_back(prerequisite[0]);
            depended_on[prerequisite[0]]++;
        }

        for(int i = 0; i < numCourses; i++)
            if(depended_on[i] == 0)
                q.push(i);

        while(q.empty() == false)
        {
            int cur_course = q.front(); q.pop();

            for(int &dependent : dependents[cur_course])
            {
                // Add current course into dependent's depends_on set.
                depends_on[dependent].insert(cur_course);

                // Add current course's depends_on into dependent's
                // depends_on set to take care of indirect dependency.
                depends_on[dependent].insert(depends_on[cur_course].begin(),
                                             depends_on[cur_course].end());

                depended_on[dependent]--;
                if(depended_on[dependent] == 0)
                    q.push(dependent);
            }
        }

        for(vector<int> &query : queries)
        {
            // is query[0] is dependent on query[1]
            if(depends_on[query[0]].find(query[1]) != depends_on[query[0]].end())
                result.push_back(true);
            else
                result.push_back(false);
        }
        return result;
    }
};