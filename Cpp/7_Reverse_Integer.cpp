/*
https://leetcode.com/problems/reverse-integer/
Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
Example 4:

Input: x = 0
Output: 0
 

Constraints:

-231 <= x <= 231 - 1

ref:
https://www.cnblogs.com/grandyang/p/4125588.html
*/

#include <iostream>

using namespace std;

int reverse(int x) {
    int ans = 0;
    while (x != 0) {
        // 檢查 overflow，不須檢查 == INT32_MAX/10 的情況，詳見ref
        if (abs(ans) > INT32_MAX / 10) return 0;
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

int main() {
    int x = 1534236469;
    int ans;
    ans = reverse(x);
    cout << ans << endl;
    cout << "INT_MAX = " << INT32_MAX << endl;
    return 0;
}