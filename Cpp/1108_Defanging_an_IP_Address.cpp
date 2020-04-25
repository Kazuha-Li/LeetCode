/*
string 用法
https://openhome.cc/Gossip/CppGossip/string2.html
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string defangIPaddr(string address) {
    }
};
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
int main() {
    string address = "255.100.50.0";
    string ans;

    ans = defangIPaddr(address);
    for (int i = 0; i < ans.length(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}