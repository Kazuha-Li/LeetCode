/*
https://leetcode.com/problems/excel-sheet-column-number/

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
 

Constraints:

1 <= s.length <= 7
s consists only of uppercase English letters.
s is between "A" and "FXSHRXW".
*/

#include <cmath>
#include <iostream>
using namespace std;

class Solution {
   public:
    int titleToNumber(string s) {
        int sum = 0, n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            // char to int 出來的數字為 acsii
            sum += (s[i] - 'A' + 1) * pow(26, n - i - 1);
        }
        return sum;
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}
