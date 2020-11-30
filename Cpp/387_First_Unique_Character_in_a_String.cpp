/*
https://leetcode.com/problems/first-unique-character-in-a-string/

Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 

Note: You may assume the string contains only lowercase English letters.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
int firstUniqChar(string s) {
    unordered_map<char, int> dict;
    for (auto chr : s) {
        if (dict.find(chr) == dict.end())
            dict[chr] = 1;
        else
            dict[chr]++;
    }
    for (int i = 0; i < s.size(); i++) {
        if (dict[s[i]] == 1) return i;
    }
    return -1;
}
*/
// 使用 vector 紀錄每個字母的出現次數
// [chr - 'a'] 字母相減代表 Ascii 相減
// Time = O(n)
// Space = O(1) 因為字母固定只有26個
int firstUniqChar(string s) {
    vector<int> cnt(26, 0);
    for (auto chr : s) {
        cnt[chr - 'a']++;
    }
    for (int i = 0; i < s.size(); i++) {
        if (cnt[s[i] - 'a'] == 1) return i;
    }
    return -1;
}

int main() {
    string s = "loveleetcode";
    int ans;

    ans = firstUniqChar(s);
    cout << ans << endl;

    return 0;
}