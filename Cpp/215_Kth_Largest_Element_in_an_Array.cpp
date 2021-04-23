/*
https://leetcode.com/problems/kth-largest-element-in-an-array/

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104

ref:
https://www.cnblogs.com/grandyang/p/4539757.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution_priority_queue {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int num : nums) pq.push(num);
        while (k > 1) {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
// quick sort 的概念
class Solution_quick_select {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = (int)nums.size() - 1;
        while (true) {
            int pos = qselect(nums, left, right);
            if (pos == k - 1) return nums.at(pos);
            if (pos > k - 1)
                right = pos - 1;
            else
                left = pos + 1;
        }
    }
    int qselect(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
        int l = start + 1, r = end;
        while (l <= r) {
            while (l <= r && nums.at(l) >= pivot) l++;
            while (l <= r && nums.at(r) <= pivot) r--;
            if (l <= r) swap(nums.at(l), nums.at(r));
        }
        swap(nums.at(start), nums.at(r));
        return r;
    }
};