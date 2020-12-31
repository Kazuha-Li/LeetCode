/*
https://leetcode.com/problems/binary-search/

Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Note:

You may assume that all elements in nums are unique.
n will be in the range [1, 10000].
The value of each element in nums will be in the range [-9999, 9999].

ref:
https://www.cnblogs.com/grandyang/p/6854825.html
https://leetcode.com/problems/binary-search/solution/

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // Time = O(logn)
    // Space = O(1)
    int search(vector<int>& nums, int target) {
        int l_num = 0, r_num = nums.size() - 1;
        while (l_num <= r_num) {
            int mid = (l_num + r_num) / 2;
            // cout << "mid = " << mid <<" "<<nums[mid]<< endl;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l_num = mid + 1;
            else
                r_num = mid - 1;
        }
        return -1;
    }
};

int main(int argc, char const* argv[]) {
    int target = 9;
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    Solution ans;

    // for (auto i : nums) cout << i << " ";
    // puts("");

    cout << ans.search(nums, target) << endl;

    return 0;
}
