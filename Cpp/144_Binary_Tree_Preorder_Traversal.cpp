/*
https://leetcode.com/problems/binary-tree-preorder-traversal/

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [1,2]
Example 5:


Input: root = [1,null,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up:

Recursive solution is trivial, could you do it iteratively?

ref:
https://www.cnblogs.com/grandyang/p/4146981.html

*/

#include <iostream>
#include <stack>
#include <vector>

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
    // DLR
    // Iterative
    // 方法 1
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (!st.empty() || p) {
            if (p) {
                // p不為空
                ans.push_back(p->val);
                st.push(p);
                // DLR 往左走
                p = p->left;
            } else {
                p = st.top()->right;
                st.pop();
            }
        }
        return ans;
    }
    /*
    // 方法 2
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* t = st.top();
            st.pop();
            ans.push_back(t->val);
            if (t->right) st.push(t->right);
            if (t->left) st.push(t->left);
        }
        return ans;
    }
    */
    /*
    // Recursive
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        DLRtraversal(root, ans);
        return ans;
    }
    void DLRtraversal(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        ans.push_back(root->val);        // D
        DLRtraversal(root->left, ans);   // L
        DLRtraversal(root->right, ans);  // R
    }
    */
};

int main(int argc, char const* argv[]) {
    return 0;
}
