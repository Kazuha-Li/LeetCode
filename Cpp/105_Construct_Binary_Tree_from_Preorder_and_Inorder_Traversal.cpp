/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.


Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

ref:
https://www.cnblogs.com/grandyang/p/4296500.html
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/

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
    // Approach 1: Recursion
    // DLR 第一個一定是 root 然後用 LDR 切分左右子樹
    // 利用 map 先記錄 inorder 的 node出現index 可加快速度
    // Time = O(n)
    // Space = O(log n)-> average, O(n) -> worst, hashmap
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }  // map, vector在傳遞時用 reference
    TreeNode* helper(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright, unordered_map<int, int>& inMap) {
        if (pleft > pright || ileft > iright) return NULL;
        // int i = ileft;
        // while(i<iright){
        //     if(preorder[pleft] == inorder[i]) break;
        //     i++;
        // }
        int i = inMap[preorder[pleft]];
        TreeNode* root = new TreeNode(preorder[pleft]);
        root->left = helper(preorder, pleft + 1, pright, inorder, ileft, i - 1, inMap);
        root->right = helper(preorder, pleft + (i - ileft + 1), pright, inorder, i + 1, iright, inMap);
        return root;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
