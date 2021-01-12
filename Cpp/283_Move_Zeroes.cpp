/*
https://leetcode.com/problems/move-zeroes/

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

ref:
https://leetcode.com/problems/move-zeroes/solution/
https://www.cnblogs.com/grandyang/p/4822732.html
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 用一個指針紀錄最前面一個 0 的位置，遇到非0就跟最前面的 0 swap
    // Time = O(n)
    // Space = O(1)
    void moveZeroes(vector<int>& nums) {
        int zerosIndex = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) swap(nums[i], nums[zerosIndex++]);
        }
    }
    /*
    void moveZeroes(vector<int>& nums) {
        int countZeros = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                countZeros++;
            else
                nums[i - countZeros] = nums[i];
        }
        for (int i = n - 1; i >= n - countZeros; i--) nums[i] = 0;
    }
    */
};

int main(int argc, char const* argv[]) {
    return 0;
}
