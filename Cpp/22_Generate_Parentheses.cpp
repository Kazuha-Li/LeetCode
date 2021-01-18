/*
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

ref:
https://www.cnblogs.com/grandyang/p/4444160.html
https://leetcode.com/problems/generate-parentheses/solution/

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 任何時候的左括號數量會大於右括號數量
    // Time及Space分析見ref
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, n, n, "");
        return res;
    }
    void helper(vector<string> &res, int left, int right, string s) {
        if (left > right) return;
        if (left == 0 && right == 0)
            res.push_back(s);
        else {
            if (left > 0) helper(res, left - 1, right, s + "(");
            if (right > 0) helper(res, left, right - 1, s + ")");
        }
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}
