/*
https://leetcode.com/problems/most-common-word/

Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in lowercase.

Example 1:

Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
Example 2:

Input: paragraph = "a.", banned = []
Output: "a"
 

Constraints:

1 <= paragraph.length <= 1000
paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
0 <= banned.length <= 100
1 <= banned[i].length <= 10
banned[i] consists of only lowercase English letters.

ref:
https://www.cnblogs.com/grandyang/p/10061930.html
https://leetcode.com/problems/most-common-word/discuss/123854/C%2B%2BJavaPython-Easy-Solution-with-Explanation

*/
// #include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 先用 isalpha() 對 paragraph 進行處理，如果不是 alphabet 則替換成' '(空格)
// 如果是字母則用 tolower() 進行小寫轉換
class Solution {
   public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> dict(banned.begin(), banned.end());
        for (char& c : paragraph) {
            if (!isalpha(c))
                c = ' ';
            else
                c = tolower(c);
        }
        pair<string, int> mostfreq("", 0);
        unordered_map<string, int> m;
        // 以空白來分割字串
        istringstream iss(paragraph);
        string word;
        while (iss >> word) {
            // cout<<word<<endl;
            if (!dict.count(word)) {
                m[word]++;
                if (m[word] > mostfreq.second) {
                    mostfreq = make_pair(word, m[word]);
                }
            }
        }
        return mostfreq.first;
    }
};