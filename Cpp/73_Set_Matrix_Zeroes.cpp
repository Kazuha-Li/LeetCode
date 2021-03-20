/*
https://leetcode.com/problems/set-matrix-zeroes/

Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

ref:
https://github.com/grandyang/leetcode/issues/73
https://leetcode.com/problems/set-matrix-zeroes/solution/

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<bool>> res(matrix.size(), vector<bool>(matrix[0].size(), false));
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) res[i][j] = true;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (res[i][j]) {
                    // cout<<"#########"<<endl;
                    std::fill(matrix[i].begin(), matrix[i].end(), 0);
                    for (int k = 0; k < m; k++) matrix[k][j] = 0;
                }
            }
        }
    }
};
class Solution_in_place {
   public:
    // 利用第一row及第一column紀錄該row or column有沒有0
    // Time = O(mn)
    // Space = O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        bool row_zero = false, column_zero = false;
        int m = matrix.size(), n = matrix[0].size();
        //判斷第一個row及第一個column是否含有0
        for (auto i : matrix[0])
            if (i == 0) row_zero = true;
        for (int j = 0; j < m; j++)
            if (matrix[j][0] == 0) column_zero = true;

        // 如果有0的話就在第一個row及第一個column做紀錄
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // i, j從1開始，最後才處理第一個row及第一個column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        // fill
        if (row_zero) std::fill(matrix[0].begin(), matrix[0].end(), 0);
        if (column_zero)
            for (int j = 0; j < m; j++) matrix[j][0] = 0;
    }
};