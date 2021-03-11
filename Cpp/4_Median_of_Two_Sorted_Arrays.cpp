/*
https://leetcode.com/problems/median-of-two-sorted-arrays/

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

Follow up: The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

ref:

*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while (i < m) {
            res.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            res.push_back(nums2[j]);
            j++;
        }
        // for (auto l : res) cout << l << ",";
        // puts("");
        int k = res.size();
        double ans;
        // cout << k << endl;
        if (k % 2 == 0)
            ans = (res[k / 2] + res[k / 2 - 1]) / 2;
        else
            ans = res[k / 2];
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    Solution res;
    cout << res.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
