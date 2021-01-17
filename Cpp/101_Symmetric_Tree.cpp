/*
https://leetcode.com/problems/symmetric-tree/

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Follow up: Solve it both recursively and iteratively.

ref:
https://www.cnblogs.com/grandyang/p/4051715.html
https://leetcode.com/problems/symmetric-tree/solution/

*/

#include <iostream>
#include <queue>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    // Iterative
    // 使用兩個 queue
    // Time = O(n)
    // Space = O(n)
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode *> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()) {
            TreeNode *t1, *t2;
            t1 = q1.front();
            t2 = q2.front();
            q1.pop();
            q2.pop();
            // 注意條件
            if (!t1 && !t2) continue;
            if ((t1 && !t2) || (!t1 && t2)) return false;
            if (t1->val != t2->val) return false;
            // 注意 push 的順序
            q1.push(t1->left);
            q2.push(t2->right);
            q1.push(t1->right);
            q2.push(t2->left);
        }
        return (q1.empty() && q2.empty());
    }
    /*
    // Recursive
    // Time = O(n)
    // Space = O(n)
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return dfs(root->left, root->right);
    }
    bool dfs(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) return true;
        if ((!root1 && root2) || (root1 && !root2) || (root1->val != root2->val)) return false;
        return dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
    }
    */
};

int main(int argc, char const *argv[]) {
    return 0;
}
