/*
https://leetcode.com/problems/maximum-subarray/

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
Example 4:

Input: nums = [-1]
Output: -1
Example 5:

Input: nums = [-2147483647]
Output: -2147483647
 

Constraints:

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1

ref:
Devide and Conquer 的解法 Time = O(nlogn)
https://www.cnblogs.com/grandyang/p/4377150.html

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // DP 優化空間
    // 因為只會使用到前一回合的資料，所以只需要兩個變數即可
    // Time = O(n)
    // Space = O(1)
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0], max_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr_sum = max(curr_sum + nums[i], nums[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
    // DP
    // 利用 vector 紀錄每回合包含 nums[i] 的最大值 dp[i] = max(要取nums[i-1]，不取nums[i-1])
    // = max(dp[i - 1] + nums[i], nums[i]);
    // Time = O(n)
    // Space = O(n) -> 有用 vector 紀錄
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), maximum = nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maximum = max(dp[i], maximum);
        }
        return maximum;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
