/*
https://leetcode.com/problems/maximum-product-subarray/

Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

ref:
https://www.cnblogs.com/grandyang/p/4028713.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// f[i] 表示子數組[0, i] 範圍內並且一定包含nums[i] 數字的最大子數組乘積
// g[i] 表示子數組[0, i] 範圍內並且一定包含nums[i] 數字的最小子數組乘積
// 此時的最大值和最小值只會在這三個數字之間產生，即 f[i-1]*nums[i]，g[i-1] *nums[i]，和nums[i]。
// 所以用三者中的最大值來更新f[i]，用最小值來更新g[i]，然後用f[i] 來更新結果res
// Time = O(n)
// Space = O(n) -> 可優化成 O(1)
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0];
        vector<int> f(n), g(n);
        f[0] = nums[0];
        g[0] = nums[0];
        for (int i = 1; i < n; i++) {
            f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
            g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
            res = max(res, f[i]);
        }
        return res;
    }
};