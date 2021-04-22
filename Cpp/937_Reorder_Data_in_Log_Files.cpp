/*
https://leetcode.com/problems/reorder-data-in-log-files/

You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
Example 2:

Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 

Constraints:

1 <= logs.length <= 100
3 <= logs[i].length <= 100
All the tokens of logs[i] are separated by a single space.
logs[i] is guaranteed to have an identifier and at least one word after the identifier.

ref:
https://www.cnblogs.com/grandyang/p/12596394.html

*/
// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// string.find()
// sort by mycompare
// Time = O(m * nlogn) -> logs.size() = n, logs[i].size() = m
// Space = O(mn)
bool mycomp(vector<string>& a, vector<string>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}
class Solution {
   public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res, digitlog;
        vector<vector<string>> data;
        for (auto log : logs) {
            auto pos = log.find(" ");
            if (isdigit(log.at(pos + 1))) {
                digitlog.push_back(log);
            } else {
                data.push_back({log.substr(0, pos), log.substr(pos + 1)});
            }
        }
        sort(data.begin(), data.end(), mycomp);
        for (auto& str : data) res.push_back(str[0] + " " + str[1]);
        for (string& s : digitlog) res.push_back(s);
        return res;
    }
};