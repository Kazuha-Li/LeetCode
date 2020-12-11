/*
https://leetcode.com/problems/top-k-frequent-elements/
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.

ref: https://leetcode.com/problems/top-k-frequent-elements/discuss/81623/Simple-C%2B%2B-solution-using-hash-table-and-bucket-sort
https://medium.com/@white1033/30%E5%A4%A9%E6%8C%91%E6%88%B0-%E7%94%A8leetcode%E4%BE%86%E5%AD%B8%E7%A8%8B%E5%BC%8F-17-top-k-frequent-elements-cca12e42bed0
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}
// Time = O(nlogn) -> 排序
// Space = O(n)
// 題意為回傳出現次數前K多的數字
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<pair<int, int>> freqcount;
    unordered_map<int, int> dict;
    // 計算每個數字出現的次數
    for (auto i : nums) {
        if (dict.find(i) == dict.end())
            dict[i] = 1;
        else
            dict[i]++;
    }
    // 依照出現次數進行排序
    for (auto d : dict) {
        freqcount.push_back(make_pair(d.first, d.second));
    }
    sort(freqcount.begin(), freqcount.end(), cmp);

    // 取前K個出現的數字為答案
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(freqcount[i].first);
    }
    return ans;
}

/*
// 利用 buckets sort 原理
// Time = O(n)
// Space = O(n)
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> dict;
    vector<vector<int>> buckets(nums.size() + 1);
    for (auto i : nums) {
        if (dict.find(i) == dict.end())
            dict[i] = 1;
        else
            dict[i]++;
    }
    // 將出現對應次數的數字 push 到 buckets 之中
    for (auto d : dict) {
        buckets[d.second].push_back(d.first);
    }
    vector<int> ans;
    for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; i--) {
        for (auto j : buckets[i])
            ans.push_back(j);
    }
    return ans;
}
*/

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ary[] = {1, 1, 1, 2, 2, 3};
    vector<int> nums;
    nums.assign(ary, ary + 6);
    int k = 2;
    vector<int> ans;

    ans = topKFrequent(nums, k);
    for (auto i : ans) {
        cout << i << ",";
    }
    puts("");
    return 0;
}
