/*
https://leetcode.com/problems/meeting-rooms/

Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti < endi <= 106

ref:
https://www.cnblogs.com/grandyang/p/5240774.html
//sort by second element
https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-1-sort-by-first-and-second/

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

bool sortbysec(const vector<int> &a,
               const vector<int> &b) {
    return (a[1] < b[1]);
}

class Solution {
   public:
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        if (intervals.size() == 0) return true;
        sort(intervals.begin(), intervals.end());
        int m = intervals.size(), n = intervals[0].size();
        for (int i = 1; i < m; i++) {
            if (intervals[i][0] < intervals[i - 1][1]) return false;
        }
        return true;
    }
};