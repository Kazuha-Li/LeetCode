/*
https://leetcode.com/problems/group-anagrams/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.

ref:
https://www.cnblogs.com/grandyang/p/4385822.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    // Time = O(m * nlogn) -> m = strs.size(), n = strs[0].size()
    // Space = O(mn)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> dict;
        for (auto s : strs) {
            string t = s;
            // 這一步sort因為本題只有26個字母，如果用counting sort = O(n)
            // 整體 Time = O(mn)
            sort(t.begin(), t.end());
            dict[t].push_back(s);
        }
        for (auto d : dict) {
            res.push_back(d.second);
        }
        return res;
    }
};

class Solution_op {
   public:
    // 與上面的時間 & 空間複雜度相同，但是有進行優化
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> dict;
        for (string str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            if (dict.count(t)) {
                res[dict[t]].push_back(str);
            } else {
                res.push_back({});
                res.back().push_back(str);
                dict[t] = res.size() - 1;
            }
        }
        return res;
    }
};