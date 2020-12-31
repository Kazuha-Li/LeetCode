/*
https://leetcode.com/problems/missing-number/

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
Example 4:

Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.
 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.

ref:
https://leetcode.com/problems/missing-number/solution/
https://www.cnblogs.com/grandyang/p/4756677.html
*/

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    // Time = O(n)
    // Space = O(1)
    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int sum = n * (n + 1) / 2;
    //     for (int i : nums) sum -= i;
    //     return sum;
    // }
    // 把 nums 裡面所有的數XOR 然後再 XOR 0~n 這樣只會有一個數字出現一次
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) ans ^= (i + 1) ^ nums[i];
        return ans;
    }
};

int main() {
    vector<int> nums;
    int target = -1;
    int arry[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    nums.assign(arry, arry + 9);

    Solution ans;
    cout << ans.missingNumber(nums) << endl;

    return 0;
}