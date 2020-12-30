/*
https://leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
 

Constraints:

-10^9 <= nums1[i], nums2[i] <= 10^9
nums1.length == m + n
nums2.length == n

ref:
http://wiki.csie.ncku.edu.tw/acm/course/Vector
https://www.cnblogs.com/grandyang/p/4059650.html
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // 使用三個pointer，從 nums1 最後面開始插入
    // Time = O(n)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int it1 = m - 1, it2 = n - 1, k = m + n - 1;
        while (it1 >= 0 && it2 >= 0) {
            if (nums1.at(it1) > nums2.at(it2)) {
                nums1.at(k) = nums1.at(it1);
                it1--;
            } else {
                nums1.at(k) = nums2.at(it2);
                it2--;
            }
            k--;
        }
        while (it2 >= 0) {
            nums1.at(k) = nums2.at(it2);
            it2--;
            k--;
        }
    }
    /*
    // 利用兩個指標 從頭開始比較
    // Time = O(n) 但是執行時間較長
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>::iterator it1, it2;
        it1 = nums1.begin();
        it2 = nums2.begin();
        // 解決尾端 0 的問題
        nums1.resize(m);
        while (it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 > *it2) {
                nums1.insert(it1, *it2);
                it1 = nums1.begin();
                it2++;
            }
            it1++;
        }
        if (it2 != nums2.end()) nums1.insert(it1, it2, nums2.end());
    }
    */
};
int main() {
    int m = 3, n = 3;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    Solution ans;
    for (int i : nums1) cout << i << ",";
    puts("");
    ans.merge(nums1, m, nums2, n);
    for (int i : nums1) cout << i << ",";
    puts("");

    return 0;
}