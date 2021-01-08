/*
https://leetcode.com/problems/squares-of-a-sorted-array/

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order. 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

ref:
https://www.cnblogs.com/grandyang/p/14172463.html

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 利用兩個指針比較前後兩數的絕對值大小
    // Time = O(n)
    // Space = O(n)
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n - 1;
        vector<int> ans(n);
        // 因為左右兩端的數平方後會是大->小，越往中間越小，所以要從後面排回來
        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                ans[i] = nums[left] * nums[left];
                left++;
            } else {
                ans[i] = nums[right] * nums[right];
                right--;
            }
        }
        return ans;
    }
    /*
    // 將大於0以及小於0的數的平方分別存在兩個vector，然後再merge
    // Time = O(n)
    // Space = O(n)
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> l1, l2, ans;
        for (int num : nums) {
            if (num < 0)
                l1.push_back(num * num);
            else
                l2.push_back(num * num);
        }
        reverse(l1.begin(), l1.end());
        // Merge
        vector<int>::iterator it1 = l1.begin(), it2 = l2.begin();
        while (it1 != l1.end() && it2 != l2.end()) {
            if (*it1 < *it2) {
                ans.push_back(*it1);
                it1++;
            } else {
                ans.push_back(*it2);
                it2++;
            }
        }
        while (it1 != l1.end()) {
            ans.push_back(*it1);
            it1++;
        }
        while (it2 != l2.end()) {
            ans.push_back(*it2);
            it2++;
        }
        return ans;
    }
    */
};

int main(int argc, char const* argv[]) {
    vector<int> nums{-4, -1, 0, 3, 10};
    Solution ans;
    vector<int> res = ans.sortedSquares(nums);

    for (auto i : res) cout << i << " ";
    puts("");

    return 0;
}
