/*
https://leetcode.com/problems/binary-tree-postorder-traversal/

Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
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
Output: [2,1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up:

Recursive solution is trivial, could you do it iteratively?

ref:
https://www.cnblogs.com/grandyang/p/4251757.html
https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45551/Preorder-Inorder-and-Postorder-Iteratively-Summarization
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

class Solution_Iterative {
   public:
    // LRD
    // Iterative
    // 修改 DLR-> DRL 然後 return reverse
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (!st.empty() || p) {
            if (p) {
                st.push(p);
                ans.push_back(p->val);
                // ans.insert(ans.begin(), p->val);
                p = p->right;  // DRL
            } else {
                p = st.top()->left;
                st.pop();
            }
        }
        return vector<int>(ans.rbegin(), ans.rend());
        // return ans;
    }
};

class Solution_Recursive {
   public:
    // Recursive
    // Time = O(n).because the recursive function is T(n)=2⋅T(n/2)+1.
    // Space complexity : The worst case space required is O(n), and in the average case it's O(logn) where n is number of nodes.
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        LRD_traversal(root, ans);
        return ans;
    }
    void LRD_traversal(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        LRD_traversal(root->left, ans);   // L
        LRD_traversal(root->right, ans);  // R
        ans.push_back(root->val);         // D
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
