/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
 

Constraints:

2 <= nums.length <= 3 * 104
-1000 <= nums[i] <= 1000
nums is sorted in increasing order.
-1000 <= target <= 1000
ref:
https://www.cnblogs.com/grandyang/p/5185815.html
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;
// 利用左右兩個指針，如果相等則回傳指針值
// 左右相加 < target 則左指針往右移
// 左右相加 > target 則右指針往右移
// Time = O(n)
// Space = O(1)
vector<int> twoSum(vector<int>& numbers, int target) {
    int lptr = 0, rptr = numbers.size() - 1;
    while (lptr < rptr) {
        int sum = numbers[lptr] + numbers[rptr];
        if (sum == target)
            return {lptr + 1, rptr + 1};
        else if (sum < target)
            lptr++;
        else
            rptr--;
    }
    return {};
}

int main() {
    vector<int> nums;
    vector<int> ans;
    int target = 9;
    int arry[] = {2, 7, 11, 15};
    nums.assign(arry, arry + 4);
    ans = twoSum(nums, target);
    cout << ans[0] << "," << ans[1] << endl;

    return 0;
}