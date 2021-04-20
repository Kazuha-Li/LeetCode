/*
https://leetcode.com/problems/robot-bounded-in-circle/

On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degrees to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

Example 1:

Input: instructions = "GGLLGG"
Output: true
Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
Example 2:

Input: instructions = "GG"
Output: false
Explanation: The robot moves north indefinitely.
Example 3:

Input: instructions = "GL"
Output: true
Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

Constraints:

1 <= instructions.length <= 100
instructions[i] is 'G', 'L' or, 'R'.

ref:
https://www.cnblogs.com/grandyang/p/14451061.html

*/
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isRobotBounded(string instructions) {
        pair<int, int> pos(0, 0);
        // w = 0, N = 1, E = 2, S = 3 mod 4
        int faceto = 1;  // initial face to N
        vector<vector<int>> direc{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int count = 0;  // 窮舉法暴力測試
        while (count < 1000) {
            for (char c : instructions) {
                // cout<<"face to = "<<faceto<<endl;
                switch (c) {
                    case 'L':
                        faceto = (faceto + 4 - 1) % 4;  // 重要! 不能直接-1
                        break;
                    case 'R':
                        faceto = (faceto + 1) % 4;
                        break;
                    case 'G':
                        pos.first += direc.at(faceto).at(0);
                        pos.second += direc.at(faceto).at(1);
                        break;
                }
            }
            if (pos.first == 0 && pos.second == 0) return true;
            count++;
        }
        return false;
    }
};