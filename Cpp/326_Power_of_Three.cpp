/*
https://leetcode.com/problems/power-of-three/

Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Example 2:

Input: n = 0
Output: false
Example 3:

Input: n = 9
Output: true
Example 4:

Input: n = 45
Output: false
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you do it without using any loop / recursion?

ref:
https://leetcode.com/problems/power-of-three/solution/
https://www.cnblogs.com/grandyang/p/5138212.html

*/

#include <iostream>
using namespace std;

class Solution {
   public:
    // Time = O(logn)
    // Space = O(1)
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return (n == 1);
    }
    /*
    // 在0~2^31 最大的三的次方數為 3^19 = 1162261467 所以只要看這個數能不能被n整除即可
    bool isPowerOfThree(int n) {
        return (n > 0 && 1162261467 % n == 0);
    }
    */
};

int main(int argc, char const *argv[]) {
    return 0;
}
