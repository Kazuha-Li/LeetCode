/*
https://leetcode.com/problems/3sum-closest/
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
ref:
https://www.cnblogs.com/grandyang/p/4510984.html
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// 方法與15_3Sum相似，增加一個判斷絕對距離
// Time = O(nlogn)(sort) + O(n^2) = O(n^2)
// Space = O(1);
int threeSumClosest(vector<int>& nums, int target) {
    int closest = 100000, sum;
    int lptr, rptr;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        lptr = i + 1;
        rptr = n - 1;
        while (lptr < rptr) {
            sum = nums[i] + nums[lptr] + nums[rptr];
            // cout << "i = " << i << ", sum = " << sum << endl;
            if (sum == target) return sum;
            if (sum < target) lptr++;
            if (sum > target) rptr--;
            if (abs(sum - target) < abs(closest - target)) closest = sum;
        }
    }

    return closest;
}

int main() {
    vector<int> nums;
    int ans;
    int target = -1;
    int arry[] = {-3, -2, -5, 3, -4};
    nums.assign(arry, arry + 5);
    ans = threeSumClosest(nums, target);

    cout << ans << endl;

    return 0;
}