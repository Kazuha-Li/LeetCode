/*
https://leetcode.com/problems/wiggle-sort/

Given an integer array nums, reorder it such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

You may assume the input array always has a valid answer.

 

Example 1:

Input: nums = [3,5,2,1,6,4]
Output: [3,5,1,6,2,4]
Explanation: [1,6,2,5,3,4] is also accepted.
Example 2:

Input: nums = [6,6,5,6,3,8]
Output: [6,6,5,6,3,8]
 

Constraints:

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 104
It is guaranteed that there will be an answer for the given input nums.
 

Follow up: Could you do it without sorting the array?

ref:
https://www.cnblogs.com/grandyang/p/5177285.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// Time = O(nlogn)
// Space = O(logn) -> sort
class Solution {
   public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if ((int)nums.size() <= 2) return;
        for (int i = 2; i < (int)nums.size(); i += 2) {
            swap(nums.at(i - 1), nums.at(i));
        }
    }
};

// 當i為奇數時，nums[i] >= nums[i - 1]
// 當i為偶數時，nums[i] <= nums[i - 1]
// 如果不符合條件則 swap
// Time = O(n)
// Space = O(1)
class Solution_ {
   public:
    void wiggleSort(vector<int>& nums) {
        if ((int)nums.size() <= 1) return;
        for (int i = 1; i < nums.size(); i++) {
            if (i % 2 == 1) {
                if (nums.at(i) < nums.at(i - 1)) swap(nums.at(i), nums.at(i - 1));
            } else {
                if (nums.at(i) > nums.at(i - 1)) swap(nums.at(i), nums.at(i - 1));
            }
        }
    }
};