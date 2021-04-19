/*
https://leetcode.com/problems/concatenated-words/

Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

 

Example 1:

Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Example 2:

Input: words = ["cat","dog","catdog"]
Output: ["catdog"]
 

Constraints:

1 <= words.length <= 104
0 <= words[i].length <= 1000
words[i] consists of only lowercase English letters.
0 <= sum(words[i].length) <= 6 * 105

ref:
https://www.cnblogs.com/grandyang/p/6254527.html

LeetCode 139

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution_recursive {
   public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;
        for (auto w : words) {
            dict.erase(w);
            vector<int> memo(w.size(), -1);
            if (!w.empty() && helper(w, dict, memo, 0)) {
                res.push_back(w);
            }
            dict.insert(w);
        }
        return res;
    }
    bool helper(string s, unordered_set<string>& dict, vector<int>& memo, int start) {
        if (start == s.size()) return true;
        if (memo[start] != -1) return memo[start];
        for (int i = start; i < s.size(); i++) {
            if (dict.count(s.substr(start, i - start + 1)) && helper(s, dict, memo, i + 1)) return memo[start] = 1;
        }
        return memo[start] = 0;
    }
};

class Solution_DP {
   public:
    // Time = O(m * n^3) -> m = words.size(), n = words[i].size()
    // Space = O(m + n)
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        vector<string> res;
        // Time = O(m) -> m = words.size()
        for (string w : words) {
            if (w.empty()) continue;
            // dict.erase(w);
            int n = w.size();
            vector<bool> dp(n + 1);
            dp[0] = true;
            // Time = O(n^2)
            for (int i = 1; i < n + 1; i++) {
                for (int j = i - 1; j >= 0; j--) {
                    // 加入 i-j < n 的判斷可以省去 dict.erase(w) 的動作，因為 i - j == n 代表該字串本身
                    // substr -> Time = O(n)
                    if (dp[j] && i - j < n && dict.count(w.substr(j, i - j))) {
                        dp[i] = true;
                        break;  // 重要! 因為只需要找到一組即可
                    }
                }
            }
            if (dp.back()) res.push_back(w);
            // dict.insert(w);
        }
        return res;
    }
};