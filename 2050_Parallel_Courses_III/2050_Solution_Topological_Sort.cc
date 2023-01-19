/*
Kahns Topological Sort Algorithm:
1. We can use topological sort to take up courses one-by-one, and if possible parallelly.
2. Create a list of dependent courses for each course (adj)
3. Count the number of courses each course depends on (indegree)
4. We use queue to do BFS. Add courses with indegree 0 into the queue.
5. As we pick the course from the queue, 
    We add its duration to time_taken.
    We update all its dependent courses time = max(time[dep], time[cur])
    Decrease the indegree of dep, if it becomes 0, add dep into the queue
6. While processing each course, keep track of the max_time among all courses.
7. Once queue is empty, return max_time
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> dependents(n+1);
        vector<int> indegree(n+1, 0);
        int max_time = 0;
        queue<int> q;
        vector<int> minTime(n+1, 0);

        for(vector<int> &relation : relations)
        {
            dependents[relation[0]].push_back(relation[1]);
            indegree[relation[1]]++;
        }

        for(int courseNum = 1; courseNum <= n; courseNum++)
        {
            if(indegree[courseNum] == 0)
                q.push(courseNum);
        }

        while(q.empty() == false)
        {
            int course = q.front(); q.pop();
            minTime[course] += time[course-1];
            max_time = max(max_time, minTime[course]);
            
            for(int &dep : dependents[course])
            {
                minTime[dep] = max(minTime[dep], minTime[course]);
                indegree[dep]--;
                if(indegree[dep] == 0)
                    q.push(dep);
            }
        }

        return max_time;
    }
};