/* 
https://leetcode.com/problems/sum-of-left-leaves/

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

ref:

*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    /*
    // 解法一：遞迴
    // 用一個 bool isLeft 判斷是否在左子樹
    // Time = O(n) n 為所有點數
    // Space = O(n)
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, false);
        return sum;
    }
    void dfs(TreeNode* root, int& sum, bool isLeft) {
        if (!root) return;
        if (root->left) dfs(root->left, sum, true);
        if (root->right) dfs(root->right, sum, false);
        if (isLeft && !root->right && !root->left) {
            sum += root->val;
        }
    }
    */
    // 解法二：iteration
    // 使用queue當輔助，當 t 有左子點且 t 的左子點為 leaf 則將數值加進去
    // Time = O(n)
    // Space = O(n)
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left && !t->left->left && !t->left->right) sum += t->left->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return sum;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
