/*
https://leetcode.com/problems/binary-tree-level-order-traversal/

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

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

class Solution_Iteration {
   public:
    // BFS
    // Time = O(n)
    // Space = O(n)
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
                q.pop();
                level.push_back(top->val);
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

class Solution_recursive {
   public:
    // Time = O(n)
    // Space = O(n)
    // 因為 res 的 index 是從 0 開始， 所以當 res.size() == level 時
    // 要重新申請一個新的 empty vector {}
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        helper(root, res, 0);
        return res;
    }
    void helper(TreeNode *root, vector<vector<int>> &res, int level) {
        if (!root) return;
        if (res.size() == level) res.push_back({});
        helper(root->left, res, level + 1);
        res[level].push_back(root->val);
        helper(root->right, res, level + 1);
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans;

    return 0;
}
