/*
https://leetcode.com/problems/permutations/

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

ref:
https://blog.roy4801.tw/2018/08/23/C++%20next_permutation:perv_permutation%E7%94%A8%E6%B3%95/
https://www.cnblogs.com/grandyang/p/4358848.html
http://catforcode.com/permutation/
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 利用每回合進行兩兩交換，因為會對nums直接操作
    // 所以換完之後要再換回來
    // Time = O(n!)
    // Space = O(n!)
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteDFS(nums, 0, res);
        return res;
    }
    void permuteDFS(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start >= nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            permuteDFS(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
    /*
    // C++ STL next_permutation()
    // 使用條件須要先排序，然後會依序列舉出下一個排列
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums);
        while (next_permutation(nums.begin(), nums.end())) {
            ans.push_back(nums);
        }
        return ans;
    }
    */
};
int main(int argc, char const* argv[]) {
    Solution ans;
    vector<int> nums = {3, 2, 1};
    vector<vector<int>> res = ans.permute(nums);
    for (auto i : res) {
        for (auto j : i) cout << j << ",";
        puts("");
    }
    puts("");
    return 0;
}
