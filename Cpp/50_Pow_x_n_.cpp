/*
https://leetcode.com/problems/powx-n/
Implement pow(x, n), which calculates x raised to the power n (i.e. xn).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104


ref:
double-and-add
https://zh.wikipedia.org/wiki/%E5%B9%B3%E6%96%B9%E6%B1%82%E5%B9%82
https://www.cnblogs.com/grandyang/p/4383775.html
*/

#include <iostream>

using namespace std;
class Solution {
   public:
    // double and add
    // Time = (logn)
    double myPow(double x, int n) {
        if (n == 0) return 1;
        // cout << "n = " << n << endl;
        double half = myPow(x, n / 2);
        // cout << "half = " << half << ", n = " << n << endl;
        if (n % 2 == 0) return half * half;  // double 無論 bit == 1 or 0 都會做 double
        if (n > 0) return half * half * x;   // add 如果 bit == 1 則會多乘一個x
        return half * half / x;              // if n < 0 因為負的代表乘上 1 / x
    }

    /*
    // double and add bitwise operation
    double myPow(double x, int n) {
        int cnt = 0, rev_n = 0;
        double ans = 1;
        if (n == -2147483648) {
            cnt = 33;
            rev_n = 1;
            x = 1 / x;
            goto myPow_;
        };
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        // 看看有幾個 bit

        while (n != 0) {
            rev_n = (rev_n << 1) | (n & 1);
            n >>= 1;
            cnt++;
        }

    myPow_:
        while (rev_n != 0) {
            int bit = rev_n & 1;
            ans *= ans;
            if (bit == 1) ans *= x;
            rev_n >>= 1;
            cnt--;
        }
        for (int i = 0; i < cnt; i++) {
            ans *= ans;
        }
        return ans;
    }
    */
};

int main() {
    double x = 2.00000;
    int n = -10;
    Solution a;
    double powerof = a.myPow(x, n);
    cout << x << " power of " << n << " = " << powerof << endl;
    // int res = 0;
    // while (n != 0) {
    //     res = (res << 1) | (n & 1);
    //     n >>= 1;
    // }
    // cout << res << endl;

    return 0;
}