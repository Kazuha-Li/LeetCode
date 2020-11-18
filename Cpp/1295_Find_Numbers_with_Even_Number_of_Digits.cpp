/*
https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
Given an array nums of integers, return how many of them contain an even number of digits.

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Time = O(n)
// Space = O(1)
int findNumbers(vector<int>& nums) {
    int ans = 0, cnt = 0;
    int tmp;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        tmp = nums[i];
        // 如果 while nums[i] >= 10 則 除以10 然後計算除了幾次
        while (tmp >= 10) {
            tmp = tmp / 10;
            cnt++;
        }
        // cnt 次數為奇數則該數的 位數為偶數
        if (cnt % 2 == 1) ans++;
        cnt = 0;  // cnt歸零
    }
    return ans;
}

/*
// 另一種作法 取 log 舉例：(int)log10(9) = 0
// 所以如果該數的位數為偶數 則 (int)log10(num) 為奇數 則 ans++
// 奇數跟 1 做 AND 運算 = 1
// 要 #include <cmath>
// Time = O(n)
// Space = O(1)
int findNumbers(vector<int>& nums) {
    int ans = 0;
    for (auto num : nums) {
        ans += (int)log10(num) & 1;
    }
    return ans;
}
*/

int main(int argc, char const* argv[]) {
    vector<int> nums;
    int ary[] = {0, 0, 0};
    nums.assign(ary, ary + 3);
    int ans;
    ans = findNumbers(nums);
    cout << ans << endl;

    return 0;
}
