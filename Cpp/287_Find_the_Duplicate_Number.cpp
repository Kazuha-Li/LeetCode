/*
https://leetcode.com/problems/find-the-duplicate-number/

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1
 

Constraints:

2 <= n <= 3 * 104
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem without modifying the array nums?
Can you solve the problem using only constant, O(1) extra space?
Can you solve the problem with runtime complexity less than O(n2)?

ref:
https://www.cnblogs.com/grandyang/p/4843654.html
*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution_set {
   public:
    // Time = O(n)
    // Space = O(n)
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto i : nums) {
            if (s.count(i))
                return i;
            else
                s.insert(i);
        }
        return 0;
    }
};
class Solution_fast_slow_pointer {
   public:
    // fast 走的路徑 = a + b + c = slow 走的路徑的兩倍 = 2(a + b)
    // 所以，a = c
    // Time = O(n)
    // Space = O(1)
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0], slow = nums[0];
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);

        slow = nums[0];
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};