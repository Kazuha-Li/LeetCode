/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

ref:
https://www.cnblogs.com/grandyang/p/4295245.html

*/

#include <iostream>
#include <vector>

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
    // Binary Search
    // 題目要求要 balanced BST 且 nums 已經進行排序
    // 想法：Inorder traversal(LDR) nums數值中間的當 root 這樣建BST就會是 balanced
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        int n = nums.size(), left = 0, right = n - 1;
        return findmid(nums, left, right);
    }
    TreeNode *findmid(vector<int> &nums, int left, int right) {
        if (left > right) return NULL;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        // 遞迴
        root->left = findmid(nums, left, mid - 1);
        root->right = findmid(nums, mid + 1, right);
        return root;
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}
