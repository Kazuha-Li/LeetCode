/*
https://leetcode.com/problems/roman-to-integer/

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Example 2:

Input: s = "IV"
Output: 4
Example 3:

Input: s = "IX"
Output: 9
Example 4:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].

ref:
https://www.cnblogs.com/grandyang/p/4120857.html
https://openhome.cc/Gossip/CppGossip/switchStatement.html

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    /*
    // 也可以用 switch 來寫
    int romanToInt(string s) {
        int n = s.size(), sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'I') {
                if (s[i + 1] == 'V' || s[i + 1] == 'X')
                    sum -= 1;
                else
                    sum += 1;
            }
            if (s[i] == 'V') sum += 5;
            if (s[i] == 'X') {
                if (s[i + 1] == 'L' || s[i + 1] == 'C')
                    sum -= 10;
                else
                    sum += 10;
            }
            // if(s[i] == 'X')sum += 10;
            if (s[i] == 'L') sum += 50;
            if (s[i] == 'C') {
                if (s[i + 1] == 'D' || s[i + 1] == 'M')
                    sum -= 100;
                else
                    sum += 100;
            }
            // if(s[i] == 'C')sum += 100;
            if (s[i] == 'D') sum += 500;
            if (s[i] == 'M') sum += 1000;
        }
        return sum;
    }
    */
    // Approach 2
    // using a dictionary
    // 如果 char 是最後一個或者 char代表的數值 >= 後一個char代表的數值，則用加法
    int romanToInt(string s) {
        unordered_map<char, int> dict = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            int val = dict[s[i]];
            if (i == s.size() - 1 || dict[s[i]] >= dict[s[i + 1]])
                sum += val;
            else
                sum -= val;
        }
        return sum;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
