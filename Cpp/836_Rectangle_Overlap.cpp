/*
https://leetcode.com/problems/rectangle-overlap/

An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.


Example 1:

Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true
Example 2:

Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false
Example 3:

Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
Output: false
 

Constraints:

rect1.length == 4
rect2.length == 4
-109 <= rec1[i], rec2[i] <= 109
rec1[0] <= rec1[2] and rec1[1] <= rec1[3]
rec2[0] <= rec2[2] and rec2[1] <= rec2[3]

ref:
https://www.cnblogs.com/grandyang/p/10367583.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

/* 
test case
[-1,0,1,1]
[0,-1,0,1]
*/

class Solution {
   public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // 處理上面 test case 如果是直線的問題
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3]) return false;
        if (rec2[0] == rec2[2] || rec2[1] == rec2[3]) return false;
        return (rec1[0] < rec2[2] && rec2[0] < rec1[2] && rec1[1] < rec2[3] && rec2[1] < rec1[3]);
    }
};
/*
               ____________________x4,y4
              |                   |
       _______|______x2,y2        |
      |       |______|____________|
      |      x3,y3   |
      |______________|
     x1,y1
*/
class Solution_area {
   public:
    // 重疊的地方會是 min(x2, x4) > max(x1, x3) && min(y2, y4) > max(y1, y3)
    // 這個方法不需要考慮直線的test case
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        return (min(x2, x4) > max(x1, x3) && min(y2, y4) > max(y1, y3));
    }
};