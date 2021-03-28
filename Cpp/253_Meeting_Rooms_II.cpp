/*
https://leetcode.com/problems/meeting-rooms-ii/

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 104
0 <= starti < endi <= 106

ref:
https://www.cnblogs.com/grandyang/p/5244720.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution_map {
   public:
    // Time = O(2n) = O(n) -> n = intervals.siez()
    // Space = O(n)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto i : intervals) {
            m[i[0]]++;
            m[i[1]]--;
        }
        int room = 0, res = 0;
        for (auto it : m) {
            res = max(res, room += it.second);
        }
        return res;
    }
};