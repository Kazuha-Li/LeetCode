/*
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
Example 3:

Input: root = [2,1,3], k = 4
Output: true
Example 4:

Input: root = [2,1,3], k = 1
Output: false
Example 5:

Input: root = [2,1,3], k = 3
Output: true
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105

ref:

*/

#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
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
class Solution {
   public:
    /*
    // BFS & unordered_map
    // Time = O(n)
    // Space = O(n)
    bool findTarget(TreeNode *root, int k) {
        unordered_map<int, int> dict;
        // BFS
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *t = q.front();
                q.pop();
                if (dict.count(k - t->val)) return true;
                dict[t->val]++;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return false;
    }
    */
    // 因為是BST，可以使用inorder traversal 得到有序的數列
    // 之後利用兩個pointer找出是否有相加等於k的數
    // Time = O(n)
    // Space = O(n)
    bool findTarget(TreeNode *root, int k) {
        vector<int> Sorted;
        // Sorted.reserve(1000);
        LDR(root, Sorted);
        int leftptr = 0, rightptr = Sorted.size() - 1;
        while (leftptr < rightptr) {
            int sum = Sorted[leftptr] + Sorted[rightptr];
            if (sum == k) return true;
            // (sum < k) ? leftptr++ : rightptr--;
            else if (sum < k)
                leftptr++;
            else
                rightptr--;
        }
        return false;
    }
    void LDR(TreeNode *root, vector<int> &Sorted) {
        if (root->left) LDR(root->left, Sorted);
        Sorted.push_back(root->val);
        if (root->right) LDR(root->right, Sorted);
    }
};

int main() {
    vector<int> nums;
    vector<int> ans;
    int target = 9;
    int arry[] = {2, 7, 11, 15};
    nums.assign(arry, arry + 4);

    return 0;
}