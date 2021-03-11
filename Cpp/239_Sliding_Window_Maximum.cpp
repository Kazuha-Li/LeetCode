/*
https://leetcode.com/problems/sliding-window-maximum/

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.


Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]
Example 5:

Input: nums = [4,-2], k = 2
Output: [4]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

ref:
https://www.cnblogs.com/grandyang/p/4656517.html
https://leetcode.com/problems/sliding-window-maximum/discuss/1070869/simple-on-deque-solution-c
https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726/C%2B%2BJavaPython-O(N)-Using-Deque
//deque
https://www.csie.ntu.edu.tw/~b01902011/material.php?type=cpp&&id=3

*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    // Approach 1: brute force
    // Time = O(n*klogk) --> TLE
    vector<int> maxSlidingWindow_bruteForce(vector<int>& nums, int k) {
        vector<int> res;
        std::vector<int>::iterator it;
        std::vector<int>::iterator end = nums.end();
        for (it = nums.begin(); it + k - 1 < end; it++) {
            vector<int> tmp;
            tmp.assign(it, it + k);
            sort(tmp.begin(), tmp.end());
            res.push_back(tmp.back());
        }
        return res;
    }

    // Approach 2: multiset

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        return res;
    }

    // Approach 3: using deque (double-ended queue)
    // deque store the index
    // the queue store only elements that need to be considered
    // Time = O(n)
    // Space = O(k)
    vector<int> maxSlidingWindow_deque(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> de;
        for (int i = 0; i < n; i++) {
            // If the de head is out of the window --> pop head
            if (!de.empty() && de.front() < i - k + 1) de.pop_front();

            // If de is non empty and nums[i] > nums[de.back()]
            // --> remove all elements that are < nums[i]
            while (!de.empty() && nums[i] > nums[de.back()]) de.pop_back();

            // inserting into the end
            de.push_back(i);

            // Store results from the end of the first window
            if (i >= k - 1) res.push_back(nums[de.front()]);
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    int k = 3;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution res;
    res.maxSlidingWindow(nums, k);
    return 0;
}
