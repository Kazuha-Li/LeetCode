/*
https://leetcode.com/problems/verifying-an-alien-dictionary/

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

 

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.

ref:
https://www.cnblogs.com/grandyang/p/13267334.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    // Time = O(m) -> m = total number of characters in words
    // Space = O(1) -> only 26 char
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dict;
        for (int i = 0; i < order.size(); i++) {
            dict[order[i]] = i;
        }
        int n = words.size();
        for (int i = 1; i < n; i++) {
            string str1 = words[i - 1];
            string str2 = words[i];
            int k = str1.size(), l = str2.size();
            for (int j = 0; j < k && j < l; j++) {
                // 符合順序，繼續往下執行，因為後面的word可能會有錯
                if (dict[str1[j]] < dict[str2[j]])
                    break;
                else if (dict[str1[j]] == dict[str2[j]])
                    continue;  // 兩個char相等繼續比對下一個char
                else
                    return false;
            }
            // 所有char皆相等，但是前面的word較長
            if (k > l && str1.substr(0, l) == str2) return false;
        }
        return true;
    }
};