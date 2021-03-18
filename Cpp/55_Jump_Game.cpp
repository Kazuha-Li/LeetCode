/*
https://leetcode.com/problems/jump-game/

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 104
0 <= nums[i] <= 105

ref:
https://leetcode.com/problems/jump-game/solution/
https://github.com/grandyang/leetcode/issues/55

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution_Greedy {
   public:
    bool canJump(vector<int>& nums) {
        int i = 0, reach = 0, n = nums.size();
        while (reach >= i && i < n) reach = max(reach, i + nums[i++]);
        return (reach >= n - 1);
    }
};

class Solution_DP {
   public:
    bool canJump(vector<int>& nums) {
    }
};