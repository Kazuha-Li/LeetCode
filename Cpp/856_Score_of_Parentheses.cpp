/* 
https://leetcode.com/problems/score-of-parentheses/

Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6
 

Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50

ref:
https://github.com/grandyang/leetcode/issues/856
http://www.cplusplus.com/reference/string/string/substr/
https://leetcode.com/problems/score-of-parentheses/discuss/141777/C%2B%2BJavaPython-O(1)-Space
https://leetcode.com/problems/score-of-parentheses/solution/

*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    // Approach 1: Divide and Conquer
    // recursion
    int scoreOfParentheses_DandC1(string S) {
        if (S == "") return 0;
        int res = 0, n = S.size();
        for (int i = 0; i < n; i++) {
            int pos = i + 1, cnt = 1;
            while (cnt != 0) {
                (S[pos] == '(') ? cnt++ : cnt--;
                pos++;
            }
            // substr(pos, length)
            int cur = scoreOfParentheses_DandC1(S.substr(i + 1, pos - i - 2));
            res += max(2 * cur, 1);
            i = pos - 1;
        }
        return res;
    }
    // 兩種方法思路相同
    // count == 0 代表是一個完整的括號，分成兩種情況
    // i - start == 1 代表裡面沒有其它括號
    // Time = O(n^2) n = s.size()
    // Space = O(n)
    int scoreOfParentheses_DandC2(string S) {
        return helper(S, 0, S.size());
    }
    int helper(string s, int start, int end) {
        int res = 0, count = 0;
        for (int i = start; i < end; i++) {
            (s[i] == '(') ? count++ : count--;
            if (count == 0) {
                if (i - start == 1)
                    res += 1;
                else
                    res += 2 * helper(s, start + 1, i);

                start = i + 1;
            }
        }
        return res;
    }
    // Approach 2: Stack
    // stack 儲存當前的值，遇到 '(' 則 push 並把 res 清成 0
    // 若遇到的是 ')' 代表此時已經形成了一個完整的合法的括號了
    // 且除去外層的括號，內層的得分已經算出來了，就是當前的結果res，此時就要乘以2，並且要跟1比較，取二者中的較大值
    // 然後還要加上stack.top()的值，因為棧頂的值是之前合法括號子串的值，跟當前的是並列關係，所以是相加的操作
    // 最後不要忘了要stack.pop()
    // Time = O(n)
    // Space = O(n)
    int scoreOfParentheses_stack(string s) {
        stack<int> st;
        int res = 0;
        for (char c : s) {
            if (c == '(') {
                st.push(res);
                res = 0;
            } else {
                res = st.top() + max(2 * res, 1);
                st.pop();
            }
        }
        return res;
    }
    // Approach 3:
    // 計算當前()外面有幾層 res += 1*(層數)
    // Time = O(n)
    // Space = O(1)
    int scoreOfParentheses_count(string s) {
        int count = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            (s[i] == '(') ? count++ : count--;
            if (s[i] == ')' && s[i - 1] == '(') res += (1 << count);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution res;
    string s = "()()()()";
    cout << res.scoreOfParentheses_DandC2(s) << endl;
    return 0;
}
