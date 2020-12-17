#include <iostream>
#include <string>
using namespace std;

string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k) {
        // 另一種解法只要一行即可
        // reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        int l = i, r;
        // i+k-1如果大於s.size()-1，則右邊的pointer r = s.size()-1
        (i + k - 1 > s.size() - 1) ? r = s.size() - 1 : r = i + k - 1;
        while (r > l) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
    return s;
}
/*
string reverseStr(string s, int k) {
    for (int i = 0; i < s.length(); i++) {
        if (i % (2 * k) == 0) {
            if (i + k > s.length()) {
                // 這邊有問題 修改l < (s.length() / 2) 邊界問題！！！
                for (int l = i; l < i + (s.length() - i) / 2; l++) {
                    char tmp = s[l];
                    s[l] = s[s.length() + i - 1 - l];
                    s[s.length() + i - 1 - l] = tmp;
                }
                break;
            } else if (i + k - 1 < s.length()) {
                for (int j = 0; j < k / 2; j++) {
                    char tmp;
                    tmp = s[j + i];
                    s[j + i] = s[i + k - 1 - j];
                    s[i + k - 1 - j] = tmp;
                }
            }
        }
    }
    return s;
}
*/
int main() {
    string s = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
    int k = 39;
    string rev;
    rev = reverseStr(s, k);

    // cout << s.length() << endl;

    cout << rev << endl;

    return 0;
}