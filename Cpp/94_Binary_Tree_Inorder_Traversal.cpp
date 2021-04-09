/*
https://leetcode.com/problems/binary-tree-inorder-traversal/

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up:

Recursive solution is trivial, could you do it iteratively?

ref:
https://leetcode.com/problems/binary-tree-inorder-traversal/solution/
https://www.cnblogs.com/grandyang/p/4297300.html

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
    // LDR
    // Morris Traversal
    // Time = O(n)
    // Space = O(1)
    // https://www.youtube.com/watch?v=wGXB9OWhPTg
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *cur = root, *pre;
        while (cur) {
            // if(不存在左節點)
            if (!cur->left) {
                ans.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                // pre 往最右邊走
                while (pre->right && pre->right != cur) pre = pre->right;
                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                } else {  // pre->right 指回到 cur
                    ans.push_back(cur->val);
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};
class Solution_Iterative {
   public:
    // Iterative use stack
    // Time = O(n)
    // Space = O(n)
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* t = root;
        while (!st.empty() || t) {
            // 方法1.
            if (t) {
                st.push(t);
                t = t->left;
            } else {
                t = st.top();
                st.pop();
                ans.push_back(t->val);
                t = t->right;
            }
            // 方法2.
            // 與方法1.效果相同
            // while (t) {
            //     st.push(t);
            //     t = t->left;
            // }
            // t = st.top();
            // st.pop();
            // ans.push_back(t->val);
            // t = t->right;
        }
        return ans;
    }
};
class Solution_recursive {
   public:
    // Recursive
    // Time complexity : O(n). The time complexity is O(n) because the recursive function is
    // T(n) = 2 T(n/2)+1.
    // Space complexity : The worst case space required is O(n), and in the average case it's O(logn)
    // where n is number of nodes.
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        LDRtraversal(root, ans);
        return ans;
    }
    void LDRtraversal(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        LDRtraversal(root->left, ans);   // L
        ans.push_back(root->val);        // D
        LDRtraversal(root->right, ans);  // R
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
