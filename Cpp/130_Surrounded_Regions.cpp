/*
https://leetcode.com/problems/surrounded-regions/
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

ref:
https://leetcode.com/problems/surrounded-regions/discuss/41612/A-really-simple-and-readable-C%2B%2B-solutionuff0conly-cost-12ms
https://www.cnblogs.com/grandyang/p/4555831.html

First, check the four border of the matrix. If there is a element is
'O', alter it and all its neighbor 'O' elements to '1'.

Then ,alter all the 'O' to 'X'

At last,alter all the '1' to 'O'

For example:

         X X X X           X X X X             X X X X
         X X O X  ->       X X O X    ->       X X X X
         X O X X           X 1 X X             X O X X
         X O X X           X 1 X X             X O X X
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 先檢查邊界的'O'把與邊界的'O'相連的'O'都標示成'1'，剩下的'O'就是被'X'包圍的
    // Time = O(4(mn)) + O(mn) = O(mn) ->第一步的dfs雖只檢查邊界但是worst可能需要整個都跑過，第二步的替換為O(mn) m,n是board的邊長
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size() || board[x][y] == 'X' || board[x][y] == '1') return;
        board[x][y] = '1';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (i == 0 || j == 0 || i == board.size() - 1 || j == board[i].size() - 1)
                    dfs(board, i, j);
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                (board[i][j] == '1') ? board[i][j] = 'O' : board[i][j] = 'X';
                // if (board[i][j] == 'O') board[i][j] = 'X';
                // if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
};

int main() {
    return 0;
}