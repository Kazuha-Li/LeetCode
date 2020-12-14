/*
https://leetcode.com/problems/balanced-binary-tree/


ref:
https://ithelp.ithome.com.tw/articles/10213283
https://www.cnblogs.com/grandyang/p/4045660.html
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

// 利用遞迴解
// Time = O(nlogn) worst = O(n^2)
/*
class Solution {
   public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + (max(maxDepth(root->left), maxDepth(root->right)));
    }
    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        if (abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
    }
};
*/
// 如果發現不符合條件直接回傳-1 不繼續計算深度
// Time = O(n)
// Space = O(1) worst = O(n) ->skrewed tree
class Solution {
   public:
    int checkDepth(TreeNode *root) {
        if (!root) return 0;
        int left = checkDepth(root->left);
        if (left == -1) return -1;
        int right = checkDepth(root->right);
        if (right == -1) return -1;
        int diff = abs(left - right);
        if (diff > 1) return -1;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        if (checkDepth(root) == -1) return false;
        return true;
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans;

    return 0;
}
