/*
https://leetcode.com/problems/check-if-the-sentence-is-pangram/

A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.


Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:

Input: sentence = "leetcode"
Output: false
 

Constraints:

1 <= sentence.length <= 1000
sentence consists of lowercase English letters.

ref:
https://leetcode.com/problems/check-if-the-sentence-is-pangram/discuss/1164047/JavaC%2B%2BPython-Set-Solution

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    bool checkIfPangram(string sentence) {
        if (sentence.size() < 26) return false;
        vector<int> cnt(26);
        for (char c : sentence) {
            cnt[c - 'a']++;
        }
        for (int i : cnt)
            if (i == 0) return false;
        return true;
    }
};

class Solution_set {
    // Time = O(n)
    // Space = O(26) = O(1)
   public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s(sentence.begin(), sentence.end());
        return s.size() == 26;
    }
};