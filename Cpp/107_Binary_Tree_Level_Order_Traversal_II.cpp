/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

ref:
https://www.cnblogs.com/grandyang/p/4051326.html
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    // BFS
    // Time = O(n)
    /*
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            for (int i = 0; i < n; i++) {
                TreeNode *top = q.front();
                level.push_back(top->val);
                q.pop();
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            // ans.insert(ans.begin(), level);
            ans.push_back(level);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    */
    // DFS 解法
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        // 題目要求要bottom up
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs(TreeNode *node, int level, vector<vector<int>> &res) {
        if (node == NULL) return;
        // 因為 level 是從0開始，如果level跟res.size()相等則要再申請新的一組空間
        if (res.size() == level) res.push_back({});
        res[level].emplace_back(node->val);
        dfs(node->left, level + 1, res);
        dfs(node->right, level + 1, res);
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans;

    return 0;
}
