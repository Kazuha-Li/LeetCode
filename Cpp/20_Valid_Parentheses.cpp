/*
https://leetcode.com/problems/valid-parentheses/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

ref:
https://www.cnblogs.com/grandyang/p/4424587.html
https://leetcode.com/problems/valid-parentheses/solution/
*/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
   public:
    // 利用stack
    // Time = O(n)
    // Space = O(n)
    bool isValid(string s) {
        stack<char> parentheses;
        for (char chr : s) {
            // 將左括號push進stack
            if (chr == '(' || chr == '[' || chr == '{')
                parentheses.push(chr);
            else {
                // 當出現右括號時
                if (parentheses.empty()) return false;
                if (chr == ')' && parentheses.top() != '(') return false;
                if (chr == ']' && parentheses.top() != '[') return false;
                if (chr == '}' && parentheses.top() != '{') return false;
                parentheses.pop();
            }
        }
        // 如果stack為空會回傳true，代表剛好兩兩配對
        // return parentheses.empty() ? true : false;
        return parentheses.empty();
    }
};

int main(int argc, char const *argv[]) {
    string s = "()[{[[{";
    Solution ans;
    cout << ans.isValid(s) << endl;
    return 0;
}
