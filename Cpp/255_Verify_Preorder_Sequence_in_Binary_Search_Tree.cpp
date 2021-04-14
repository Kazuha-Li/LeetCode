/*
https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/

Given an array of unique integers preorder, return true if it is the correct preorder traversal sequence of a binary search tree.

 

Example 1:


Input: preorder = [5,2,1,3,6]
Output: true
Example 2:

Input: preorder = [5,2,6,1,3]
Output: false
 

Constraints:

1 <= preorder.length <= 104
1 <= preorder[i] <= 104
All the elements of preorder are unique.
 

Follow up: Could you do it using only constant space complexity?

ref:
https://www.cnblogs.com/grandyang/p/5327635.html

*/
// #include <bits/stdc++.h>

#include <climits>  // INT_MIN
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// DLR
class Solution {
   public:
    // Time = O(n)
    // Space = O(n)
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int mini = INT_MIN;
        for (int num : preorder) {
            if (num < mini) return false;
            // 注意要用 while，找到該子樹的root
            while (!st.empty() && num > st.top()) {
                mini = st.top();
                st.pop();
            }
            st.push(num);
        }
        return true;
    }
};