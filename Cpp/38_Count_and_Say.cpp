/* 
https://leetcode.com/problems/count-and-say/

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

For example, the saying and conversion for digit string "3322251":


Given a positive integer n, return the nth term of the count-and-say sequence.

 

Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 

Constraints:

1 <= n <= 30

ref:
https://leetcode.com/problems/count-and-say/solution/
https://www.cnblogs.com/grandyang/p/4086299.html

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    // 解法二
    string countAndSay(int n) {
        string res = "1";
        // 這一步要執行 n-1 次
        while (n - 1 > 0) {
            string cur = "";
            int count = 1;
            for (int i = 0; i < res.size(); i++) {
                if (res[i] == res[i + 1])
                    count++;
                else {
                    cur += to_string(count) + res[i];
                    count = 1;
                }
            }
            res = cur;
            n--;
        }
        return res;
    }

    /*
    // 解法一
    // Time = O(2^n)
    string countAndSay(int n) {
        vector<string> dp(n + 1, "");
        dp[1] = "1";
        string res = "";
        for (int i = 2; i < n + 1; i++) {
            int count = 1;
            string tmp = dp[i - 1];
            for (int j = 0; j < tmp.size(); j++) {
                if (tmp[j] == tmp[j + 1]) {
                    count++;
                } else {
                    res += to_string(count) + tmp[j];
                    count = 1;
                }
            }
            dp[i] = res;
            res = "";
        }
        return dp[n];
    }
    */
};

int main(int argc, char const *argv[]) {
    return 0;
}
