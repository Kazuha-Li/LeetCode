/*
https://leetcode.com/problems/minimum-distance-between-bst-nodes/

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105

ref:
https://www.cnblogs.com/grandyang/p/9062143.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// LDR inorder traversal
// Time = O(n)
// Space = O(n)
class Solution {
    vector<int> res;

   public:
    int minDiffInBST(TreeNode* root) {
        int minDist = INT_MAX;
        dfs(root);
        for (int i = 1; i < res.size(); i++) {
            minDist = min(minDist, res[i] - res[i - 1]);
        }
        return minDist;
    }
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
};