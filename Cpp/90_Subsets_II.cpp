/*
https://leetcode.com/problems/subsets-ii/
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

ref:
https://www.cnblogs.com/grandyang/p/4310964.html
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 與78.Subsets相似 還有另一種 backtracking 遞迴的做法
// 先對nums進行sort，這樣相同的數字會在一起連續出現
// Time = O(2^n) n = nums.size()
// Space = O(2^n)
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans(1);
    if (nums.empty()) return ans;
    // sort
    sort(nums.begin(), nums.end());
    // 處理第一個
    ans.push_back(ans[0]);
    ans.back().push_back(nums[0]);
    // 此時的 ans.size() == 2，有{{}，{nums[0]}}，n 代表前一個回合的ans.size()
    int n = 1;
    for (int i = 1; i < nums.size(); i++) {
        // 判斷下一個迴圈的start，如果這回合的數字跟前一回合相等，則 start 從前一回合的 n 開始
        // 代表只有上一回合新增的subset加上這一回合的nums[i]才能增加不重複的 subset
        int start = (nums.at(i) == nums.at(i - 1)) ? n : 0;
        n = ans.size();
        for (int j = start; j < n; j++) {
            ans.push_back(ans[j]);
            ans.back().push_back(nums[i]);
        }
    }
    return ans;
}

int main(int argc, char const* argv[]) {
    vector<int> nums;
    vector<vector<int>> ans;
    int arry_A[] = {1, 2, 2, 2};

    nums.assign(arry_A, arry_A + 4);

    ans = subsetsWithDup(nums);

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
