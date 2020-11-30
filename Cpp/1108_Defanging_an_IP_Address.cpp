/*
https://leetcode.com/problems/defanging-an-ip-address/

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
string 用法
https://openhome.cc/Gossip/CppGossip/string2.html
*/

#include <iostream>
#include <regex>
#include <string>

using namespace std;

/*
string defangIPaddr(string address) {
    string answer;
    for (int i = 0; i < address.length(); i++) {
        string tmp = ".";
        if (address[i] == tmp[0]) {
            // answer += "[.]";
            answer += "[";
            answer += address[i];
            answer += "]";
            continue;
        }
        answer += address[i];
        // answer += address[i];
    }
    return answer;
}
*/
// 'a'表示是一個字符,"a"表示一個字符串相當於'a'+'\0'
// https://bbs.csdn.net/topics/20311409
// Time = O(n)
// Space = O(1)
/*
string defangIPaddr(string address) {
    string ans;
    for (auto num : address) {
        if (num == '.')
            ans += "[.]";
        else
            ans += num;
    }
    return ans;
}
*/

// 正規表示式 (Regular expression) with regex (using character class: [])
// https://blog.csdn.net/qq_34802416/article/details/79307102#4_regex_replace_85
// https://leetcode.com/problems/defanging-an-ip-address/discuss/442529/CC%2B%2BJavaPythonCPHPRubyJavaScriptGoRustSwift-regex-and-replace
string defangIPaddr(string address) {
    return regex_replace(address, regex("[.]"), "[.]");
}

int main() {
    string address = "255.100.50.0";
    string ans;

    ans = defangIPaddr(address);
    cout << ans << endl;

    return 0;
}