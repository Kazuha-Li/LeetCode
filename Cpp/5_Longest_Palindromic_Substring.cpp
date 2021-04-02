/* 
https://leetcode.com/problems/longest-palindromic-substring/

Given a string s, return the longest palindromic substring in s. 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),

ref:
https://leetcode.com/problems/longest-palindromic-substring/solution/
https://www.cnblogs.com/grandyang/p/4464476.html

Manacher's Algorithm 馬拉車算法
https://www.cnblogs.com/grandyang/p/4475985.html

*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution_expend_around_center {
   public:
    // 解法一、brute force
    // 從頭開始每一個點找 palindrome，要注意奇數偶數的問題，例如："aba","abba"
    // maxLen紀錄長度
    // Time = O(n^2)
    // Space = O(1)
    string longestPalindrome(string s) {
        int maxLen = 0, n = s.size(), start = 0;
        if (n < 2) return s;
        for (int i = 0; i < n - 1; i++) {
            findSub(s, i, i, maxLen, start);
            findSub(s, i, i + 1, maxLen, start);
        }
        return s.substr(start, maxLen);
    }
    void findSub(string s, int left, int right, int &maxLen, int &start) {
        // left, right 兩個指針往兩邊走並且確認 s[left] == s[right]
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        if (maxLen < right - left - 1) {
            maxLen = right - left - 1;
            start = left + 1;
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution_expend_around_center res;
    string s1 = "xaabacxcabaaxcabaax";
    string s2 = "ccc";
    string ans = res.longestPalindrome(s2);
    cout << ans << endl;
    return 0;
}
