/*
https://leetcode.com/problems/course-schedule-ii/

There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.

ref:
https://leetcode.com/problems/course-schedule-ii/solution/
https://www.cnblogs.com/grandyang/p/4504793.html

*/
// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Time = O(V+E) -> V = vertex, E = edge
// Space = O(V+E)
class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> G(n, vector<int>());
        vector<int> in(n, 0);
        queue<int> q;
        vector<int> res;
        // 使用 &p 可以節省 memory
        for (auto& p : prerequisites) {
            G[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            for (int j : G[t]) {
                in[j]--;
                if (in[j] == 0) q.push(j);
            }
        }
        // for (auto i : in)if (i > 0) return {};
        if (res.size() != n) return {};
        return res;
    }
};