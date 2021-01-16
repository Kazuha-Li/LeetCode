/*
https://leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

ref:
https://www.cnblogs.com/grandyang/p/4428207.html
https://leetcode.com/problems/next-permutation/solution/

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 要找到下一個比目前的排列還要大的排列
    // 例如：1 2 7 4 3 1 --> 1 3 1 2 4 7
    // 先從後面找到第一個比 2 大的數 3 swap(2,3)-->1 3 7 4 2 1
    // 之後 reverse (7 4 2 1) --> 1 2 4 7
    // 1 3 1 2 4 7
    // Time = O(n)
    // Space = O(1)
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2, j = n - 1;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i >= 0) {
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }

    /*
    // STL next_permutation
    void nextPermutation(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        next_permutation(nums.begin(), nums.end());
    }
    */
};

int main(int argc, char const* argv[]) {
    return 0;
}
