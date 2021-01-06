/*
https://leetcode.com/problems/sqrtx/

Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.


Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1

ref:
https://leetcode.com/problems/sqrtx/discuss/25057/3-4-short-lines-Integer-Newton-Every-Language
https://youtu.be/p8u_k2LIZyo
https://www.cnblogs.com/grandyang/p/4346413.html

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 還有一種方法 牛頓疊代法，詳見 ref
    // binary search
    // Time = (logx)
    int mySqrt(int x) {
        if (x <= 1) return x;
        int left = 0, right = x;
        while (left < right) {
            long mid = (left + right) / 2;
            if (mid * mid <= x)
                left = mid + 1;
            else
                right = mid;
        }
        return right - 1;
    }
    /*
    // brute force
    int mySqrt(int x) {
        for (int i = 0; i < x; i++) {
            if (i * i <= x && (i + 1) * (i + 1) > x) return i;
        }
    }
    */
};
int main() {
    int m = 3, n = 3;
    // vector<int> nums1{1, 2, 3, 0, 0, 0};
    // vector<int> nums2{2, 5, 6};
    int x = 64;
    Solution ans;

    cout << ans.mySqrt(x) << endl;

    return 0;
}