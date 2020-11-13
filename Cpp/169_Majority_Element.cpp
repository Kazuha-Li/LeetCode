/*
https://leetcode.com/problems/majority-element/
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
https://medium.com/leetcode-%E6%BC%94%E7%AE%97%E6%B3%95%E6%95%99%E5%AD%B8/048-leetcode-169%E6%BC%94%E7%AE%97%E6%B3%95-majority-element-%E6%B1%82%E5%A4%9A%E6%95%B8%E5%85%83%E7%B4%A0-1d8af4ca951a
https://ithelp.ithome.com.tw/articles/10213285
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// vector 找 argmax 的方式
// 需要 #include <algorithm>
// vector<int> cnt_pos(10000, 0);
// int pos_argmax = distance(cnt_pos.begin(), max_element(cnt_pos.begin(), cnt_pos.end()));

/*
// 用 unordered_map 一一對應
// Time = O(n)
// Space = O(n)
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> dict;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (dict.find(nums[i]) == dict.end())
            dict[nums[i]] = 1;
        else
            dict[nums[i]]++;
        if (dict[nums[i]] > n / 2) return nums[i];
    }
    return 0;
}

// sort
// Time = O(nlogn)
// Space = O(n)
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}
*/
// Boyer–Moore majority vote algorithm
/*
https://medium.com/leetcode-%E6%BC%94%E7%AE%97%E6%B3%95%E6%95%99%E5%AD%B8/048-leetcode-169%E6%BC%94%E7%AE%97%E6%B3%95-majority-element-%E6%B1%82%E5%A4%9A%E6%95%B8%E5%85%83%E7%B4%A0-1d8af4ca951a
假設真的過了1/2的數字的話，每一個數字去消除另一個數字結果還會剩下他
舉個簡單的例子，假設現在有[1,3,8,7,2,3,3]，1跟3消除，8跟7不一樣也消除，2跟3不一樣也消除，剩下一個就是3
主要是因為過半數這個規則在，所以可以用這種解法來處理這一題。
Time = O(n)
Space = O(1)
*/
int majorityElement(vector<int>& nums) {
    int cnt = 0;
    int candidate;
    for (int i = 0; i < nums.size(); i++) {
        if (cnt == 0)
            candidate = nums[i];
        if (candidate == nums[i])
            cnt++;
        else
            cnt--;
    }
    return candidate;
}

int main(int argc, char const* argv[]) {
    vector<int> nums;
    int ary[] = {7, 7, 5, 7, 5, 7, 5, 7, 5, 5, 7, 7, 7, 4, 5, 7};
    nums.assign(ary, ary + 16);
    int ans;
    ans = majorityElement(nums);

    cout << "ans = " << ans << endl;

    return 0;
}
