/*
https://leetcode.com/problems/plus-one/

Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.


Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Example 3:

Input: digits = [0]
Output: [1]
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9

ref:
https://www.cnblogs.com/grandyang/p/4079357.html

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 解法2
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] == 9)
                digits[i] = 0;
            else {
                digits[i]++;
                return digits;
            }
        }
        if (digits[0] == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
    // 解法1
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1]++;
        if (digits[digits.size() - 1] == 10) {
            vector<int>::iterator it = digits.end() - 1;
            while (it != digits.begin() && *it == 10) {
                *it = 0;
                it--;
                *it += 1;
            }
            if (*it == 10) {
                *it = 0;
                digits.insert(digits.begin(), 1);
            }
        }
        return digits;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
