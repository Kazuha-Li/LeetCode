/*
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
ref:
https://leetcode.com/problems/longest-common-prefix/solution/
https://www.cnblogs.com/grandyang/p/4606926.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution_sort {
   public:
    // C++ sort會按照字典順序排序，所以只要比對第一個及最後一個的LCP即可
    // Time = O(l*nlogn) -> l = string.length, n = strs.size()
    // Space = O(l + long(n))
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        sort(strs.begin(), strs.end());
        string res = "";
        int n = min(strs[0].size(), strs.back().size());
        for (int i = 0, j = 0; i < n && j < n; i++, j++) {
            if (strs[0][i] != strs.back()[j]) break;
            res += strs[0][i];
        }
        return res;
    }
};
class Solution_brute_force {
   public:
    // Time = O(l*n) -> l = string.length, n = strs.size()
    // Space = O(l)
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return res;
                }
            }
            res += c;
        }
        return res;
    }
};