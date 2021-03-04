/*
https://leetcode.com/problems/invert-binary-tree/

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.

ref:
https://leetcode.com/problems/invert-binary-tree/solution/

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
    /*
    // Approach 1: Recursive
    // 先遞迴往下走，然後兩兩交換左右child
    // Time = O(n) ->每個節點皆訪問過一次
    // Space = O(n) ->tree height worst case = O(n)
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    */
    // Approach 2: Iterative
    // we create a queue to store nodes whose left and right child have not been swapped yet.
    // Initially, only the root is in the queue.
    // As long as the queue is not empty, remove the next node from the queue, swap its children,
    // and add the children to the queue. Null nodes are not added to the queue.
    // Eventually, the queue will be empty and all the children swapped, and we return the original root.
    // Time = O(n)
    // Space = O(n)
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* t = node->left;
            node->left = node->right;
            node->right = t;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
