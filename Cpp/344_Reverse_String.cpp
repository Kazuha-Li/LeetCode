/*
https://leetcode.com/problems/reverse-string/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// Time = O(n)
// Space = O(1)
void reverseString(vector<char>& s) {
    // 方法一
    // return reverse(s.begin(), s.end());
    // 方法二
    // char tmp;
    // int n = s.size();
    // for (int i = 0; i < n / 2; i++) {
    //     tmp = s[i];
    //     s[i] = s[n - 1 - i];
    //     s[n - 1 - i] = tmp;
    // }
    // 方法三
    int i = 0, j = s.size() - 1;
    while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

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

    for (auto c : s) {
        cout << c << ",";
    }
    cout << endl;

    reverseString(s);
    for (auto a : s) {
        cout << a << ",";
    }
    puts("");

    return 0;
}
