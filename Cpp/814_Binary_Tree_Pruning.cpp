/*
https://leetcode.com/problems/binary-tree-pruning/

We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.

Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

Example 1:
Input: [1,null,0,0,1]
Output: [1,null,0,null,1]
 
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.


Example 2:
Input: [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]



Example 3:
Input: [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]



Note:

The binary tree will have at most 200 nodes.
The value of each node will only be 0 or 1.

ref:
https://www.cnblogs.com/grandyang/p/9539584.html
https://leetcode.com/problems/binary-tree-pruning/discuss/122730/C%2B%2BJavaPython-Self-Explaining-Solution-and-2-lines
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

// Time = O(n), n = number of nodes in the tree
// Space = O(n), worst case -> skrewed tree
class Solution {
   public:
    // 遞迴修剪所有 val = 0 的 leaf node
    TreeNode *pruneTree(TreeNode *root) {
        if (!root) return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        // return (root->left == NULL && root->right == NULL && root->val == 0) ? NULL : root;
        // 上面這一行的意思等於下面這兩行
        if (root->left == NULL && root->right == NULL && root->val == 0) return NULL;
        return root;
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans;

    return 0;
}
