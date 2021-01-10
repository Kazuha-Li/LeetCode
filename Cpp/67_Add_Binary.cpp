/*
https://leetcode.com/problems/add-binary/

Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

ref:
https://www.cnblogs.com/grandyang/p/4084971.html
https://leetcode.com/submissions/detail/441110387/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // Time = O(max(m,n))
    // Space = O(max(m,n))
    string addBinary(string a, string b) {
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        string ans = "";
        while (m >= 0 || n >= 0) {
            // a[m--] - '0' << 轉成 int 要減'0'是因為 ascii code
            // 如果沒辦法取出char 則當作是0
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            // ans = char(sum % 2 + '0') + ans; // 轉成 char 要加回 ascii
            ans = to_string(sum % 2) + ans;
            carry = sum / 2;
        }
        // if (carry == 1) return ("1" + ans);
        // else return ans;
        return (carry == 1) ? ("1" + ans) : ans;
    }

    /*
    // 解法 1
    string addBinary(string a, string b) {
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        if (m > n)
            for (int i = 0; i < m - n; i++) b.insert(b.begin(), '0');
        if (m < n)
            for (int i = 0; i < n - m; i++) a.insert(a.begin(), '0');
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        m = a.size() - 1;
        while (m >= 0) {
            cout << "a = " << a << endl;
            cout << "carry = " << carry << endl;
            if (carry) {
                if (a[m] == '0' && b[m] == '0') {
                    a[m] = '1';
                    carry--;
                } else if (a[m] == '1' && b[m] == '1') {
                } else
                    a[m] = '0';

            } else {
                if (a[m] == '1' && b[m] == '1') {
                    carry++;
                    a[m] = '0';
                } else if (a[m] == '0' && b[m] == '0')
                    a[m] = '0';
                else
                    a[m] = '1';
            }
            m--;
        }
        if (carry) a.insert(a.begin(), '1');
        return a;
    }
    */
};

int main(int argc, char const* argv[]) {
    string a = "11";
    string b = "1";
    Solution ans;
    cout << ans.addBinary(a, b) << endl;

    // cout << s[s.size() - 1] << endl;
    return 0;
}
