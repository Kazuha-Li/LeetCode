#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string reverseStr(string s, int k) {
        return s;
    }
};
string reverseStr(string s, int k) {
    for (int i = 0; i < s.length(); i++) {
        if (i % (2 * k) == 0) {
            // cout << "i = " << i << endl;
            if (i + k > s.length()) {
                // cout << "i = " << i << endl;
                // cout << "i+k = " << i + k << endl;
                // 這邊有問題 修改l < (s.length() / 2) 邊界問題！！！
                for (int l = i; l < i + (s.length() - i) / 2; l++) {
                    // cout << "l = " << l << endl;
                    char tmp = s[l];
                    s[l] = s[s.length() + i - 1 - l];
                    s[s.length() + i - 1 - l] = tmp;
                    // cout << "#######################################" << endl;
                    // cout << s.length() + i - 1 - l << endl;
                    // cout << s[s.length() + i - 1 - l] << endl;
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

int main() {
    string s = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
    int k = 39;
    string rev;
    rev = reverseStr(s, k);

    // for (int i = 0; i < s.length(); i++) {
    //     if (i % 2 == 0) {
    //         char tmp;
    //         tmp = s[i];
    //         s[i] = s[i + 1];
    //         s[i + 1] = tmp;
    //     }
    // }
    cout << s.length() << endl;

    cout << rev << endl;

    return 0;
}