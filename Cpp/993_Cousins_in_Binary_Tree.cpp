/*
https://leetcode.com/problems/cousins-in-binary-tree/

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.

ref:
https://www.cnblogs.com/grandyang/p/14255174.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    // 102. Binary Tree Level Order Traversal
    // Time = O(n)
    // Space = O(n)
    bool isCousins(TreeNode* root, int x, int y) {
        int levelx = -1, levely = -2, level = 0;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->val == x) levelx = level;
                if (t->val == y) levely = level;
                if (t->left && t->right) {
                    if ((t->left->val == x && t->right->val == y) || (t->left->val == y && t->right->val == x)) return false;
                }
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (levelx == levely) return true;
            level++;
        }
        return false;
    }
};