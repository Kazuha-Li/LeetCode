/*
https://leetcode.com/problems/top-k-frequent-words/

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.

ref:
https://www.cnblogs.com/grandyang/p/7689927.html
347. Top K Frequent Elements

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

bool mycomp(pair<string, int> &a, pair<string, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
// 利用map計算每個string出現次數，之後用vector排序
// Time = O(nlogn) -> n = words.size()
// Space = O(n)
class Solution_vector {
   public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> m;
        vector<pair<string, int>> dict;
        for (auto &w : words) {
            m[w]++;
        }
        for (auto &i : m) {
            dict.push_back(make_pair(i.first, i.second));
        }
        sort(dict.begin(), dict.end(), mycomp);
        vector<string> res;
        for (auto &s : dict) {
            if (k-- == 0) break;
            res.push_back(s.first);
        }
        return res;
    }
};
// Time = O(nlogn)
// Space = O(n)
class Solution_priority_queue {
   public:
    struct mycomp {
        bool operator()(pair<string, int> &a, pair<string, int> &b) {
            if (a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> m;
        for (auto &w : words) m[w]++;

        priority_queue<pair<string, int>, vector<pair<string, int>>, mycomp> pq;

        for (auto &i : m) {
            pq.push(make_pair(i.first, i.second));
        }

        vector<string> res;
        while (k > 0) {
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return res;
    }
};