/*
https://leetcode.com/problems/minimum-depth-of-binary-tree/
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
ref:
https://www.cnblogs.com/grandyang/p/4042168.html
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
    // 遞迴解法
    /*
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        // 如果右子樹為空
        if (!root->right) return 1 + minDepth(root->left);
        // 如果左子樹為空
        if (!root->left) return 1 + minDepth(root->right);
        return 1 + min(minDepth(root->right), minDepth(root->left));
    }
    */
    // BFS
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        queue<TreeNode *> q;
        int ans = 0;
        q.push(root);
        while (!q.empty()) {
            ans++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *top = q.front();
                q.pop();
                // if 左右子樹皆為空，則代表這個點是 leaf 回傳 ans
                if (top->left == NULL && top->right == NULL)
                    return ans;
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
