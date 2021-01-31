/* 
https://leetcode.com/problems/valid-palindrome/

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.

ref:
https://www.cnblogs.com/grandyang/p/4030114.html
https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case

*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    /*
    // 解法一
    // 注意要處理大小寫問題
    // Time = O(n)
    // Space = O(1)
    bool isPalindrome(string s) {
        // to lowercase
        for (char &c : s) // 要用 &c 才能修改
            if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
        // isalnum();
        int front = 0, back = s.size() - 1;
        while (front < back) {
            while (front < back && !isalphanumeric(s[front])) front++;
            while (front < back && !isalphanumeric(s[back])) back--;
            if (s[front] != s[back]) return false;
            front++;
            back--;
        }
        return true;
    }
    // 判斷是否為字母以及數字
    bool isalphanumeric(char c) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
        return false;
    }
    */
    // 解法二
    // 同解法一，使用內建函數 isalnum()
    bool isPalindrome(string s) {
        // to lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int front = 0, back = s.size() - 1;
        while (front < back) {
            while (front < back && !isalnum(s[front])) front++;
            while (front < back && !isalnum(s[back])) back--;
            if (s[front] != s[back]) return false;
            front++;
            back--;
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    // cout << isalnum(',') << endl;
    // int t = 'a' - 'A';
    // cout << t << endl;
    string s = "A man, a plan, a canal: Panama";
    for (char &c : s)
        if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
    cout << s << endl;
    return 0;
}
