/* 
https://leetcode.com/problems/transpose-matrix/

Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 105
-109 <= matrix[i][j] <= 109

ref:
https://leetcode.com/problems/transpose-matrix/solution/
https://www.cnblogs.com/grandyang/p/10727029.html

*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    /*
    // Approach 1:
    // Time = O(mn)
    // Space = O(mn)
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        for (int j = 0; j < matrix[0].size(); j++) {
            vector<int> res;
            for (int i = 0; i < matrix.size(); i++) {
                res.push_back(matrix[i][j]);
            }
            ans.push_back(res);
        }
        return ans;
    }
    */
    // 不用 push_back
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // 可以先保留 memory 空間
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                res[j][i] = matrix[i][j];
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
