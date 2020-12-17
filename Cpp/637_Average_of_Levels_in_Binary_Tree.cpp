/*
https://leetcode.com/problems/average-of-levels-in-binary-tree/
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

ref:
https://www.cnblogs.com/grandyang/p/7259209.html
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

class Solution {
   public:
    // BFS
    // 可參考 102、107.cpp
    // Time = O(n)
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            double sum = 0;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *t = q.front();
                q.pop();
                sum += t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            ans.emplace_back(sum / n);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans;

    return 0;
}
