/*
https://leetcode.com/problems/reverse-string/

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

ref:
https://www.cnblogs.com/grandyang/p/5420836.html
https://leetcode.com/problems/reverse-string/solution/

*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // Approach 1: C++ STL
    // Time = O(n)
    // Space = O(1)
    void reverseString_STL(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
    // Approach 2: 2 pointers
    // Time = O(n)
    // Space = O(1)
    void reverseString_swap1(vector<char>& s) {
        char tmp;
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            tmp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = tmp;
        }
    }
    // 同 Approach 2
    // 使用 swap 函式
    void reverseString_swap2(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) swap(s[i++], s[j--]);
    }
};

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char arry[] = {'h', 'e', 'l', 'l', 'o'};
    vector<char> s;
    s.assign(arry, arry + 5);
    int n = 5;
    cout << n / 2 << endl;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++) {
    //     char tmp;
    //     cin >> tmp;
    //     s.push_back(tmp);
    // }

    return 0;
}
