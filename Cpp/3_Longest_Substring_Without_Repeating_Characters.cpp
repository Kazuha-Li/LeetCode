/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

ref:
https://www.cnblogs.com/grandyang/p/4480780.html

*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    /*
    // Sliding Window
    // 解法一：Use HashMap 以及一個最左端的指標
    // Time = O(n)
    // Space = O(1) 因為 ASCII 只有128個
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> m;  // 紀錄 s[i] = index
        int left = -1, n = s.size(), maxLength = 0;
        for (int i = 0; i < n; i++) {
            // 如果s[i]已經出現過且index > left 代表在 window 內
            if (m.count(s[i]) && left < m[s[i]]) {
                maxLength = max(maxLength, i - left - 1);
                left = max(left, m[s[i]]);  // 更新 left
                // left 會指向 window 最前端的前一個元素
            }
            m[s[i]] = i;
        }
        maxLength = max(maxLength, n - 1 - left);
        return maxLength;
    }
    */
    // 解法二：use vector
    // 想法與上面類似
    // Time = O(n)
    // Space = O(1)
    int lengthOfLongestSubstring(string s) {
        int left = -1, maxLength = 0, n = s.size();
        vector<int> m(128, -1);
        for (int i = 0; i < n; i++) {
            // 省略 if 的比較，如果s[i]不在 window 裡
            // 則 m[s[i]] < left
            left = max(m[s[i]], left);
            m[s[i]] = i;
            maxLength = max(maxLength, i - left);
        }
        return maxLength;
    }
    // 解法三：Set
    // int lengthOfLongestSubstring(string s) {

    // }
};

int main(int argc, char const *argv[]) {
    Solution ans;
    string s = "bbbbba";
    cout << ans.lengthOfLongestSubstring(s) << endl;
    return 0;
}
