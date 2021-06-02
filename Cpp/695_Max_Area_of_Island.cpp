/*
https://leetcode.com/problems/max-area-of-island/

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.

ref:
https://www.cnblogs.com/grandyang/p/7712724.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// 參考 200. Number of Islands
// 利用 countArea 計算每次遞迴的 island 的面積
// 離開遞迴後與 maxArea 比較
// Time = O(4mn) = O(mn)
// Space = O(mn) -> 可優化成 O(1)
class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int countArea = 0;
                    dfs(grid, visited, i, j, countArea);
                    maxArea = max(maxArea, countArea);
                }
            }
        }
        return maxArea;
    }
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int &countArea) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0) return;
        countArea++;
        visited[i][j] = true;
        dfs(grid, visited, i + 1, j, countArea);
        dfs(grid, visited, i - 1, j, countArea);
        dfs(grid, visited, i, j + 1, countArea);
        dfs(grid, visited, i, j - 1, countArea);
    }
};

// Space = O(1)
class Solution_space_optimisation {
   public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int maxArea = 0, countArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, countArea);
                    maxArea = max(maxArea, countArea);
                    countArea = 0;
                }
            }
        }
        return maxArea;
    }
    void dfs(vector<vector<int>> &grid, int i, int j, int &countArea) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return;
        countArea++;
        grid[i][j] = -1;
        dfs(grid, i + 1, j, countArea);
        dfs(grid, i - 1, j, countArea);
        dfs(grid, i, j + 1, countArea);
        dfs(grid, i, j - 1, countArea);
    }
};