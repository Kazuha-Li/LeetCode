/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2]
Explanation: Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the returned length.
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4]
Explanation: Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively. It doesn't matter what values are set beyond the returned length.
 

Constraints:

0 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in ascending order.

ref:
https://leetcode.com/problems/remove-duplicates-from-sorted-array/solution/
https://www.cnblogs.com/grandyang/p/4329128.html
https://elloop.github.io/c++/2015-12-19/learning-using-stl-56-unique

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // 利用兩個指針，如果nums[i] == nums[slow] 則繼續往下一個檢查
    // 當 nums[i] != nums[slow]，將nums[i]覆蓋到nums[slow]的下一個
    // 最後return slow + 1
    // Time = O(n)
    // Space = O(1)
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int slow = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[slow]) nums[++slow] = nums[i];
            // slow++; nums[slow] = nums[i];
        }
        return slow + 1;
    }
    /*
    // 使用<algorithm>裡面的 std::unique 函數
    // 這個函數會回傳第一個出現重複的指標，所以減掉nums.begin() 得到 index
    int removeDuplicates(vector<int>& nums) {
        auto it = unique(nums.begin(), nums.end());
        return it - nums.begin();
    }
    */
};

int main(int argc, char const* argv[]) {
    return 0;
}
