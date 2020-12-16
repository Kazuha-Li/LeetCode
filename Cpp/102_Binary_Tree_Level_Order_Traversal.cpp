/*
https://leetcode.com/problems/binary-tree-level-order-traversal/


ref:
https://www.cnblogs.com/grandyang/p/4051321.html
https://www.geeksforgeeks.org/level-order-tree-traversal/
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
    // 還有一種遞迴解法 https://www.cnblogs.com/grandyang/p/4051321.html
    vector<vector<int>> levelOrder(TreeNode *root) {
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
            ans.push_back(level);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans;

    return 0;
}
