/*
https://leetcode.com/problems/word-break/

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.


Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

ref:
https://github.com/grandyang/leetcode/issues/139

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution_brute_force_recursive {
   public:
    // TLE
    // start 紀錄 substr 起點
    // 將string 切成兩段，前半段存在wordDict && 後半段存在wordDict才是 true
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return helper(s, wordDict, dict, 0);
    }
    bool helper(string& s, vector<string>& wordDict, unordered_set<string>& dict, int start) {
        if (start == (int)s.size()) return true;
        for (int i = start; i < (int)s.size(); i++) {
            if (dict.count(s.substr(start, i - start + 1)) && helper(s, wordDict, dict, i + 1)) {
                return true;
            }
        }
        return false;
    }
};
class Solution_recursive_with_memo {
    vector<int> memo;
    // 使用memo來存中間狀態
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        memo.resize(s.size(), -1);  // 初始化
        return helper(s, wordDict, dict, 0);
    }
    bool helper(string& s, vector<string>& wordDict, unordered_set<string>& dict, int start) {
        if (start == (int)s.size()) return true;
        // 如果已經有結果就直接回傳
        if (memo[start] != -1) return memo[start];
        for (int i = start; i < (int)s.size(); i++) {
            if (dict.count(s.substr(start, i - start + 1)) && helper(s, wordDict, dict, i + 1)) return memo[start] = 1;
        }
        return memo[start] = 0;
    }
};

class Solution2 {
   public:
    // Time = O(n^3) -> substr time = O(n)
    // Space = O(n)
    // dp[i] = [0,i) 內的子字串是否可拆 = [0,j) to [j,i) = dp[j] && [j,i)
    // dp.size() == n + 1 因為初始化空字串為true
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = (int)s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i < n + 1; i++) {
            // for(int j = 0; j < i; j++){
            for (int j = i - 1; j >= 0; j--) {
                // because dp.size() = s.size() + 1, so substr(j,i-1) 不用 j+1
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};