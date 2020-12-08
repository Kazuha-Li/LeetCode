/*
https://leetcode.com/problems/sort-array-by-increasing-frequency/
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100

ref: https://leetcode.com/problems/sort-array-by-increasing-frequency/discuss/917674/C%2B%2BPython3-Sort-by-Count
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// pair<int,int> 比較大小方法，如果 a.second == b.second 則依照pair的第一個數做降序排序
// 否則，依照第二個數做升序排序
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}
/*
vector<int> frequencySort(vector<int>& nums) {
    vector<pair<int, int>> freqcount;
    unordered_map<int, int> dict;
    for (auto i : nums) {
        if (dict.find(i) == dict.end())
            dict[i] = 1;
        else
            dict[i]++;
    }
    for (auto d : dict) {
        freqcount.push_back(make_pair(d.first, d.second));
    }
    sort(freqcount.begin(), freqcount.end(), cmp);
    vector<int> ans;
    for (auto i : freqcount) {
        for (int j = 0; j < i.second; j++)
            ans.push_back(i.first);
    }
    return ans;
}
*/
// Time = O(nlogn) -> 因為Sort
// Space = O(1) cnt[201]陣列是固定的
vector<int> frequencySort(vector<int>& nums) {
    int cnt[201] = {};
    for (auto n : nums)
        ++cnt[n + 100];
    // sort(begin(nums), end(nums), [&](int a, int b) {
    //     return cnt[a + 100] == cnt[b + 100] ? a > b : cnt[a + 100] < cnt[b + 100];
    // });
    // 這兩段意思是一樣的，如果兩數的個數相同則降序排列
    sort(nums.begin(), nums.end(), [&](int a, int b) {
        if (cnt[a + 100] == cnt[b + 100]) return a > b;
        return cnt[a + 100] < cnt[b + 100];
    });
    return nums;
}

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ary[] = {1, 1, 2, 2, 2, 3};
    vector<int> nums;
    nums.assign(ary, ary + 6);
    vector<int> ans;

    ans = frequencySort(nums);
    for (auto i : ans) {
        cout << i << ",";
    }
    puts("");

    return 0;
}
