/*
https://leetcode.com/problems/subsets/
Given an integer array nums, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10

ref:
https://leetcode.com/problems/subsets/solution/
https://www.cnblogs.com/grandyang/p/4309345.html
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
// 還有其他解法
// Time = O(2^n) n = nums.size()
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans(1);
    for (int num : nums) {
        // ans.size()是變動的，不直接放在停止條件
        int n = ans.size();
        for (int i = 0; i < n; i++) {
            // 把前面的所有元素再push_back進ans一次並且加上新的num
            ans.push_back(ans[i]);
            ans.back().push_back(num);
        }
    }
    return ans;
}

int main(int argc, char const* argv[]) {
    vector<int> nums;
    vector<vector<int>> ans;
    int arry_A[] = {1, 2, 3};

    nums.assign(arry_A, arry_A + 3);

    ans = subsets(nums);

    for (auto i : ans) {
        cout << "(";
        for (auto j : i) {
            cout << j << " ";
        }
        puts(")");
    }
    puts("");
    // cout << "ans = " << ans << endl;

    return 0;
}
