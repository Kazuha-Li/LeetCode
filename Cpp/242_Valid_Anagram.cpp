/*
https://leetcode.com/problems/valid-anagram/

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

ref:

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 利用一個 vector 去紀錄每個字符出現的次數
    // Time = O(n)
    // Space = O(26) = O(1)
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        // int count[26] = {0};
        for (char chr : s) count[chr - 'a']++;
        for (char chr : t) count[chr - 'a']--;
        for (int num : count)
            if (num != 0) return false;
        return true;
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}
