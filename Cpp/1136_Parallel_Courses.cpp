/*
https://leetcode.com/problems/parallel-courses/

You are given an integer n which indicates that we have n courses, labeled from 1 to n. You are also given an array relations where relations[i] = [a, b], representing a prerequisite relationship between course a and course b: course a has to be studied before course b.

In one semester, you can study any number of courses as long as you have studied all the prerequisites for the course you are studying.

Return the minimum number of semesters needed to study all courses. If there is no way to study all the courses, return -1.


Example 1:


Input: n = 3, relations = [[1,3],[2,3]]
Output: 2
Explanation: In the first semester, courses 1 and 2 are studied. In the second semester, course 3 is studied.
Example 2:


Input: n = 3, relations = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: No course can be studied because they depend on each other.
 

Constraints:

1 <= n <= 5000
1 <= relations.length <= 5000
1 <= a, b <= n
a != b
All the pairs [a, b] are unique.

ref:
https://leetcode.com/problems/parallel-courses/solution/
*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        n++;
        vector<vector<int>> G(n, vector<int>());
        vector<int> in(n, 0);
        for (auto v : relations) {
            // cout<<v[0]<<v[1]<<endl;
            G[v[0]].push_back(v[1]);
            in[v[1]]++;
        }
        int res = 0;
        queue<int> q;
        for (int i = 1; i < n; i++) {
            if (in[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int m = q.size();
            for (int i = 0; i < m; i++) {
                int tmp = q.front();
                q.pop();
                // cout<<"tmp = "<<tmp<<endl;
                for (auto l : G[tmp]) {
                    in[l]--;
                    if (in[l] == 0) q.push(l);
                }
            }
            res++;
        }
        for (int i : in)
            if (i > 0) return -1;
        return res;
    }
};