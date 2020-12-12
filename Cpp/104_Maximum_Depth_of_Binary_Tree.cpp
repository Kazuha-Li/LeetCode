/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Example 2:

Input: root = [1,null,2]
Output: 2
Example 3:

Input: root = []
Output: 0
Example 4:

Input: root = [0]
Output: 1

ref:https://www.cnblogs.com/grandyang/p/4051348.html
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

// 利用遞迴解
// Time = O(n)
class Solution {
   public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + (max(maxDepth(root->left), maxDepth(root->right)));
    }
};
// BFS
// Time = O(n)
int maxDepth(TreeNode *root) {
    if (root == NULL) return 0;
    queue<TreeNode *> q;
    q.push(root);
    int ans = 0;
    while (!q.empty()) {
        ans++;
        // 這邊要注意因為q.size()是變動的不能直接寫在終止條件裡面
        int n = q.size();
        for (int i = 0; i < n; i++) {
            // TreeNode *tmp = q.front(); // 意思與下一行同
            auto tmp = q.front();
            q.pop();
            // 要先判斷左右子樹是否存在
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans;

    return 0;
}
