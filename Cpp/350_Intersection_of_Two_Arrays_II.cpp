/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

ref:
https://www.cnblogs.com/grandyang/p/5533305.html
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    // Time = O(n)
    // Space = O(n)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> ans;
        // 計算每個數字出現的次數，第二個int為出現次數
        for (int num : nums1) {
            if (dict.count(num))
                dict[num]++;
            else
                dict[num] = 1;
        }
        // 如果該數字在dict裡面出現次數大於0，則push_back進ans
        for (int num : nums2) {
            if (dict.count(num)) {
                if (dict[num] > 0) {
                    dict[num]--;
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
