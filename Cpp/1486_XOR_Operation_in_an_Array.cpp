/*
https://leetcode.com/problems/xor-operation-in-an-array/
Given an integer n and an integer start.

Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.

Return the bitwise XOR of all elements of nums.

 

Example 1:

Input: n = 5, start = 0
Output: 8
Explanation: Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
Where "^" corresponds to bitwise XOR operator.
Example 2:

Input: n = 4, start = 3
Output: 8
Explanation: Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) = 8.

O(1)解法
https://leetcode.com/problems/xor-operation-in-an-array/discuss/712915/C%2B%2B-O(1)-with-Detailed-Explanation
*/
#include <iostream>
using namespace std;

int xorOperation(int n, int start) {
    int ans = start;
    for (int i = 1; i < n; i++) {
        ans = ans ^ (start + 2 * i);
    }
    return ans;
}

int main(int argc, char const* argv[]) {
    int n = 5;
    int start = 0;
    int ans;
    ans = xorOperation(n, start);
    cout << "answer = " << ans << endl;
    return 0;
}
