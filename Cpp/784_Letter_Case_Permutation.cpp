/*
https://leetcode.com/problems/letter-case-permutation/

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

 

Example 1:

Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: S = "3z4"
Output: ["3z4","3Z4"]
Example 3:

Input: S = "12345"
Output: ["12345"]
Example 4:

Input: S = "0"
Output: ["0"]
 

Constraints:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.

ref:
https://www.cnblogs.com/grandyang/p/9065702.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// Time = O(n * 2^n) 總共 2^n 種可能，每次在res.push_back 耗費 O(n)
// Space = O(n * 2^n)
class Solution {
   public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        helper(s, 0, res);
        return res;
    }
    void helper(string &s, int pos, vector<string> &res) {
        if (pos == s.size()) {
            res.push_back(s);
            return;
        }
        // XOR 32 可以改變大<=>小寫
        helper(s, pos + 1, res);
        if (isalpha(s.at(pos))) {
            s.at(pos) ^= 32;
            helper(s, pos + 1, res);
        }
        /*
        // 兩種寫法
        if(isdigit(s.at(pos))){
            helper(s,pos+1,res);
            return;
        }
        s.at(pos) = tolower(s.at(pos));
        helper(s ,pos+1,res);
        s.at(pos) ^= 32;
        helper(s ,pos+1,res);
        */
    }
};