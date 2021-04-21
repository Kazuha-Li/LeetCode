/*
https://leetcode.com/problems/n-ary-tree-level-order-traversal/

Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 

Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 104]

ref:
https://www.cnblogs.com/grandyang/p/9672233.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int x) {
        val = x;
    }
    Node(int x, vector<Node*> _children) {
        val = x;
        children = _children;
    }
};

// Time = O(n)
// Space = O(n)
class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node*> q{{root}};
        vector<vector<int>> res;
        while (!q.empty()) {
            int n = (int)q.size();
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                Node* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                for (Node* child : t->children) {
                    q.push(child);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
