/*
https://leetcode.com/problems/pascals-triangle/

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

ref:
https://leetcode.com/problems/pascals-triangle/
https://www.cnblogs.com/grandyang/p/4032449.html

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 解法二：
    // Time = O(n^2)
    // Space = O(n^2)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>());
        for (int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
    /*
    // 解法一：
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            if (i == 0)
                ans.push_back({1});
            else if (i == 1)
                ans.push_back({1, 1});
            else {
                vector<int> column;
                for (int j = 0; j < i + 1; j++) {
                    if (j == 0 || j == i)
                        column.push_back(1);
                    else {
                        column.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                    }
                }
                ans.push_back(column);
            }
        }
        return ans;
    }
    */
};

int main(int argc, char const *argv[]) {
    return 0;
}
