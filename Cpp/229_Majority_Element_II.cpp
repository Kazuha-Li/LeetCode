/*
https://leetcode.com/problems/majority-element-ii/
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]

https://ithelp.ithome.com.tw/articles/10213286
https://medium.com/leetcode-%E6%BC%94%E7%AE%97%E6%B3%95%E6%95%99%E5%AD%B8/049-leetcode-229%E6%BC%94%E7%AE%97%E6%B3%95-majority-element-ii-%E6%B1%82%E5%A4%9A%E6%95%B8%E5%85%83%E7%B4%A0-ii-29e436bd1f08
*/
// 對 ans 排序之後刪除重複的元素
// Time = O(nlogn)
// sort(ans.begin(),ans.end());
// ans.erase(unique(ans.begin(), ans.end()), ans.end());

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
// unorder_map
// Time = O(n)
// Space = O(n)
vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> dict;
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (dict.find(nums[i]) == dict.end())
            dict[nums[i]] = 1;
        else
            dict[nums[i]]++;
    }
    // 查找 dict 裡面的所有元素
    for(auto d : dict){
        if(d.second > n/3) ans.push_back(d.first);
    }

    return ans;
}
*/

/*
Boyer–Moore majority vote algorithm
本題最多只會有兩個答案，令兩個變數及兩個count
最後要再確認 candidate1 及 candidate2 是否符合題目要求
Time = O(n)
Space = O(1)
*/
vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    int candidate1 = INT32_MAX, candidate2 = INT32_MAX, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate1)
            cnt1++;
        else if (nums[i] == candidate2)
            cnt2++;
        else if (cnt1 == 0) {
            candidate1 = nums[i];
            cnt1 = 1;
        } else if (cnt2 == 0) {
            candidate2 = nums[i];
            cnt2 = 1;
        } else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate1) cnt1++;
        if (nums[i] == candidate2) cnt2++;
    }
    if (cnt1 > n / 3)
        ans.push_back(candidate1);
    if (cnt2 > n / 3)
        ans.push_back(candidate2);
    return ans;
}

int main(int argc, char const* argv[]) {
    vector<int> nums;
    int ary[] = {0, 0, 0};
    nums.assign(ary, ary + 3);
    vector<int> ans;
    ans = majorityElement(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    puts("");
    return 0;
}
