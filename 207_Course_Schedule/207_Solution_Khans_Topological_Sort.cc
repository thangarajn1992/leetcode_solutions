/* Kahn's Topological Sort Approach:
    Keep track of courses that are dependent on each course using adj_list
    Keep count of number of courses each course depends on using indegree
    Add courses with no dependencies into the queue.
    Do BFS using queue and for each course completed, reduce depends on for its dependent.
    If any course dependencies becomes 0, add it into the queue
    Once BFS is done, check whether we completed all the courses.
*/
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // courses that depends on this course to be completed
        vector<vector<int>> dependents(numCourses);
        // No. of courses this course depends on
        vector<int> depended_on(numCourses, 0);
        queue<int> q;
        int course_completed = 0;

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
            course_completed++;

            for(int &dependent : dependents[cur_course])
            {
                depended_on[dependent]--;
                if(depended_on[dependent] == 0)
                    q.push(dependent);
            }
        }

        return course_completed == numCourses;
    }
};