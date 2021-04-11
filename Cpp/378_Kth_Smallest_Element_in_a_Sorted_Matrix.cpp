/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.


Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length
n == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-degreasing order.
1 <= k <= n2

ref:
https://www.cnblogs.com/grandyang/p/5727892.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    // Max Heap priority_queue -> 最大值會在第一個元素
    // Time = O(n)
    // Space = O(n)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<int> q;
        for (auto i : matrix) {
            for (auto j : i) {
                q.push(j);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};
// 有 O(logn) 的解法