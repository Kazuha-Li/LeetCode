/*
https://leetcode.com/problems/contains-duplicate-ii/
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
利用unordered_map來儲存，如果該元素已經在map裡面，
則檢查 |i-j|是否<=k。
// Time = O(n)
// Space = O(n)
*/
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> dict;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (dict.find(nums[i]) == dict.end())
            dict[nums[i]] = i;
        else if (i - dict[nums[i]] <= k) {
            return true;
        } else
            dict[nums[i]] = i;
    }
    return false;
}

int main(int argc, char const* argv[]) {
    vector<int> nums;
    int ary[] = {1, 2, 3, 1, 2, 3};
    nums.assign(ary, ary + 6);
    int k = 2;
    bool ans;
    ans = containsNearbyDuplicate(nums, k);
    cout << ans << endl;

    return 0;
}
