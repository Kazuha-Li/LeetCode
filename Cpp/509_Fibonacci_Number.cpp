/* 
https://leetcode.com/problems/fibonacci-number/

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

 

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

Constraints:

0 <= n <= 30

ref:
https://leetcode.com/problems/fibonacci-number/solution/
https://www.cnblogs.com/grandyang/p/10306787.html

*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    /*
    // 解法一
    // DP
    // Time = O(n)
    // Space = O(n)
    int fib(int n) {
        if (n == 0) return 0;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    */
    // 解法二
    // DP 空間優化
    // Time = O(n)
    // Space = O(1)
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a = 0, b = 1, sum;
        for (int i = 2; i < n + 1; i++) {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
    /*
    // 解法三
    // 數學，黃金比例
    // sqrt 開根號，round 四捨五入，pow 次方
    // Time = O(logn) pow method takes logn time.
    // Space = O(1)
    int fib(int n) {
        double goldenRatio = (1 + sqrt(5)) / 2;
        return (int)round(pow(goldenRatio, n) / sqrt(5));
    }
    */
};
int main(int argc, char const *argv[]) {
    return 0;
}
