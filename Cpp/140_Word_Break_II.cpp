/*
https://leetcode.com/problems/word-break-ii/

Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
 

Constraints:

1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

ref:
https://www.cnblogs.com/grandyang/p/4576240.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return helper(s, wordDict);
    }
    vector<string> helper(string s, vector<string>& wordDict) {
        // 如果是空字串則return ""，用來判斷是否為最後一個 word
        if (s.empty()) return {""};
        vector<string> res;
        for (auto word : wordDict) {
            // 針對 wordDict 裡面每個 word 取出來與 s 比對
            if (s.substr(0, word.size()) != word) continue;
            // s.substr(word.size()) -> 會從 word.size()這個位置取到 s 的最尾端
            vector<string> rem = helper(s.substr(word.size()), wordDict);
            for (string str : rem) {
                // 判斷是否為最後一個 word
                res.push_back(word + (str.empty() ? "" : " ") + str);
                // cout<<"str.size() = "<<str.size()<<"\n";
                // cout<<"word = "<<word<<" , "<<res.back()<<endl;
            }
        }
        return res;
    }
};

// 使用 memo 紀錄已經查找過的狀態，避免重複查詢
class Solution_with_memo {
    unordered_map<string, vector<string>> memo;

   public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return helper(s, wordDict);
    }
    vector<string> helper(string s, vector<string>& wordDict) {
        if (memo.count(s)) return memo[s];  // memo
        if (s.empty()) return {""};
        vector<string> res;
        for (auto word : wordDict) {
            if (s.substr(0, word.size()) != word) continue;
            vector<string> rem = helper(s.substr(word.size()), wordDict);
            for (string str : rem) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return memo[s] = res;  // memo
    }
};

int main(int argc, char const* argv[]) {
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    Solution ans;
    vector<string> res = ans.wordBreak(s, wordDict);
    for (auto w : res) cout << w << ",";
    puts("");
    return 0;
}
