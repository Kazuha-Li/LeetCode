/*
https://leetcode.com/problems/contains-duplicate/
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

ref:
https://leetcode.com/problems/contains-duplicate/solution/
http://www.cplusplus.com/reference/algorithm/unique/
https://www.geeksforgeeks.org/stdunique-in-cpp/
http://www.cplusplus.com/reference/algorithm/sort/
https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/
// set用法
https://vimsky.com/zh-tw/examples/usage/set-count-function-in-c-stl.html
https://www.cnblogs.com/grandyang/p/4537029.html
*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// 先對 nums 進行 sort
// 使用 unique 找出是否有重複 該函數會回傳第一個重複元素的指標位置
// Time = O(nlogn)
// Space = O(1)
bool containsDuplicate(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sort(nums.begin(), nums.end());
    vector<int>::iterator it;
    it = unique(nums.begin(), nums.end());
    if (it == nums.end())
        return false;
    else
        return true;
}
class Solution {
   public:
    // Approach 1: brute force -> Time = O(n^2) -> TLE
    // 每一個逐一比較

    // Approach 2: Sort
    // 先排序之後再比較前後是否相等
    // Time = O(nlogn) ->sort + O(n) = O(nlogn)
    // Space = O(1) -> 取決於sort
    bool containsDuplicate_Sort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }

    // Approach 3: Hash Table
    // 使用 unordered_map 先 find num 是否在 dict 中
    // 若不在 dict 中則將 num 加入到 dict 中
    // 若 num 已經存在 dict 中，則 return true
    // Time = O(n)
    // Space = O(n)
    bool containsDuplicate_umap(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (auto num : nums) {
            if (dict.find(num) == dict.end())
                dict[num] = 1;
            else
                return true;
        }
        return false;
    }
    // 也可以用 set
    // set.count 用來算個數
    // 由於set容器僅包含唯一元素，因此只能返回1或0。
    bool containsDuplicate_uset(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums) {
            if (s.count(i))
                return true;
            else
                s.insert(i);
        }
        return false;
    }
};

int main(int argc, char const* argv[]) {
    vector<int> nums;
    int ary[] = {0, 0, 0};
    nums.assign(ary, ary + 3);
    bool ans;
    ans = containsDuplicate(nums);
    cout << ans << endl;

    return 0;
}
