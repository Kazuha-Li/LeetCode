/*
https://leetcode.com/problems/sort-characters-by-frequency/

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 利用 ASCII 轉換統計每個 char 出現的次數
// Time = O(n) -> n 為字串長度 Sort長度最大為128個元素與n無關所以為 constant time
// Space = O(n)
string frequencySort(string s) {
    // 因為 ASCII 有 0~127
    vector<int> res(128, 0);
    string ans;
    ans.reserve(s.size());
    // 計算 char 出現次數
    for (auto chr : s) res[int(chr)]++;
    vector<pair<int, char>> collect;
    for (int i = 0; i < 128; i++) {
        if (res[i] > 0)
            collect.emplace_back(make_pair(res[i], i));
    }
    // 用 r.begin() r.end() 做降序排列
    sort(collect.rbegin(), collect.rend());
    for (auto item : collect) {
        // ans.append(次數, 字符)
        ans.append(item.first, item.second);
    }
    // vector<int> res2(res.begin(), res.end());
    // sort(res2.rbegin(), res2.rend());
    // vector<int>::iterator it;
    // for (auto num : res2) {
    //     if (num > 0) {
    //         it = find(res.begin(), res.end(), num);
    //         auto tmp = distance(res.begin(), it);
    //         for (int i = 0; i < num; i++) {
    //             ans += (char)(tmp);
    //             res[tmp] = 0;
    //         }
    //     }
    // }
    return ans;
}

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cout << int('a') - 71 << endl;
    string s = "tree";
    string ans = frequencySort(s);
    cout << s << endl;
    cout << ans << endl;

    return 0;
}
