/*
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

ref:


*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// Definition for a binary tree node.
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
    // 參考 LeetCode.105
    // postorder = LRD 最後一個是 root 由右往左 buile tree
    unordered_map<int, int> inMap;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inl, int inr, int pol, int por) {
        if (inl > inr || pol > por) return NULL;
        int i = inMap[postorder[por]];
        TreeNode* root = new TreeNode(postorder[por]);
        root->right = helper(inorder, postorder, i + 1, inr, pol, por - 1);
        root->left = helper(inorder, postorder, inl, i - 1, pol, por - (inr - i + 1));
        return root;
    }
};