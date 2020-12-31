/*
https://leetcode.com/problems/intersection-of-two-arrays/

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.

ref:
https://www.cnblogs.com/grandyang/p/5507129.html

*/
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    // 利用兩個set，先把nums1放進去set
    // 然後針對nums2裡面的元素去搜尋是否在set裡面
    // 若存在則 insert 進去 ans 的 set，最後再轉成 vector 的形式 return
    // m = nums1.size(); n = nums2.size();
    // Time = O(m) + O(n)
    // Space = O(m) + O(n)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> dict(nums1.begin(), nums1.end());
        set<int> ans;
        for (int num : nums2)
            if (dict.count(num)) ans.insert(num);
        return vector<int>(ans.begin(), ans.end());
    }
    /*
    // 對 nums2 進行 sort，然後取出nums1裡面的元素使用binary search進行搜尋
    // m = nums1.size(); n = nums2.size();
    // Time => 排序 = O(nlogn) 搜尋 = O(mlogn)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        std::sort(nums2.begin(), nums2.end());
        // 使用 set 消除重複元素
        set<int> ans;
        for (int num : nums1) {
            if (binarySearch(nums2, num)) ans.insert(num);
        }
        return vector<int>(ans.begin(), ans.end());
    }
    bool binarySearch(vector<int>& nums, int target) {
        int l_num = 0, r_num = nums.size() - 1;
        while (l_num <= r_num) {
            int mid = (l_num + r_num) / 2;
            if (target == nums[mid])
                return true;
            else if (target > nums[mid])
                l_num = mid + 1;
            else
                r_num = mid - 1;
        }
        return false;
    }
    */
};

int main(int argc, char const* argv[]) {
    int target = 9;
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    Solution ans;

    // for (auto i : nums) cout << i << " ";
    // puts("");

    // cout << ans.search(nums, target) << endl;

    return 0;
}
