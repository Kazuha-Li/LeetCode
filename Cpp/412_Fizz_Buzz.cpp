/*
https://leetcode.com/problems/fizz-buzz/

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // Time = O(n)
    vector<string> fizzBuzz(int n) {
        // vector<string> ans;
        vector<string> ans(n);
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0)
                ans[i - 1] = "FizzBuzz";
            // ans.push_back("FizzBuzz");
            else if (i % 3 == 0)
                ans[i - 1] = "Fizz";
            // ans.push_back("Fizz");
            else if (i % 5 == 0)
                ans[i - 1] = "Buzz";
            // ans.push_back("Buzz");
            else
                ans[i - 1] = to_string(i);
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    Solution ans;
    for (auto i : ans.fizzBuzz(15)) cout << i << " ";
    puts("");
    return 0;
}
