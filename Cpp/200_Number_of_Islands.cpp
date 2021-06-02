/*
https://leetcode.com/problems/number-of-islands/

Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

ref:
https://www.cnblogs.com/grandyang/p/4402656.html

*/
#include <iostream>
#include <vector>

using namespace std;

// Time = O(4mn) = O(mn) -> m = grid.size(), n = grid[0].size()
// Space = O(mn)
class Solution_ {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j, visited);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || visited[i][j]) return;
        visited[i][j] = true;
        dfs(grid, i + 1, j, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i, j - 1, visited);
    }
};
class Solution {
   public:
    // 利用DFS遞迴去查看，如果等於1就把目前位置改成0，然後往四個方向去找
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x > grid.size() || y < 0 || y > grid[x].size()) return;
        grid[x][y] = '0';

        // 與下面幾行相同，執行時間差異不大
        if (x + 1 >= 0 && x + 1 < grid.size() && grid[x + 1][y] == '1') dfs(grid, x + 1, y);
        if (x - 1 >= 0 && x - 1 < grid.size() && grid[x - 1][y] == '1') dfs(grid, x - 1, y);
        if (y + 1 >= 0 && y + 1 < grid[x].size() && grid[x][y + 1] == '1') dfs(grid, x, y + 1);
        if (y - 1 >= 0 && y - 1 < grid[x].size() && grid[x][y - 1] == '1') dfs(grid, x, y - 1);

        // for (int dx = -1; dx <= 1; dx++) {
        //     int nx = x + dx;
        //     if (0 <= nx && nx < grid.size() && grid[nx][y] == '1') dfs(grid, nx, y);
        // }
        // for (int dy = -1; dy <= 1; dy++) {
        //     int ny = y + dy;
        //     if (0 <= ny && ny < grid[x].size() && grid[x][ny] == '1') dfs(grid, x, ny);
        // }

        return;
    }
    // 整體的 Time = O(4mn) = O(mn) mn為grid的長寬
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    // 如果有1則從這邊開始
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}