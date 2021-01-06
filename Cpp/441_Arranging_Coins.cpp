/*
https://leetcode.com/problems/arranging-coins/

You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.

ref:
https://leetcode.com/problems/arranging-coins/solution/
https://www.cnblogs.com/grandyang/p/6026066.html

*/

#include <cmath>
#include <iostream>
using namespace std;

class Solution {
   public:
    // Binary Search
    // Time = O(logn)
    // Space = O(1)
    int arrangeCoins(int n) {
        // 邊界條件
        if (n <= 1) return n;
        int left = 0, right = n;
        while (left < right) {
            // 用int會overflow
            long mid = (left + right) / 2;
            // cout << "left = " << left << endl;
            // cout << "right = " << right << endl;
            // cout << "mid = " << mid << endl;
            if (mid * (mid + 1) / 2 > n)
                right = mid;
            else
                left = mid + 1;
        }
        return right - 1;
    }
    /*
    // math
    // Time = O(1)
    // Space = O(1)
    int arrangeCoins(int n) {
        return (int)(sqrt(2 * (double)n + 0.25) - 0.5);
    }
    */
};

int main(int argc, char const *argv[]) {
    int n = 2147483647;

    Solution ans;
    cout << ans.arrangeCoins(n) << endl;

    return 0;
}
