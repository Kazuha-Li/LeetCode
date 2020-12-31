/*
https://leetcode.com/problems/single-number/

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?


Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

ref:
https://leetcode.com/problems/single-number/solution/
https://www.cnblogs.com/grandyang/p/4130577.html
*/

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    // 將所有數 XOR 起來 因為XOR具有結合律及交換律
    // A XOR A = 0，0 XOR A = A
    // Time = O(n)
    // Space = O(1)
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
    // 利用 set 如果不在 set 裡面就 insert
    // 如果已經在 set 裡面就 erase，最後set裡面只會剩下只出現一次的那個數
    // Time = O(n)
    // Space = O(n)
    /*
    int singleNumber(vector<int>& nums) {
        unordered_set<int> dict;
        for (int i : nums) {
            if (dict.count(i))
                dict.erase(i);
            else
                dict.insert(i);
        }
        return *dict.begin();
    }
    */
};

int main() {
    vector<int> nums;
    int target = -1;
    int arry[] = {4, 1, 2, 1, 2};
    nums.assign(arry, arry + 5);

    Solution ans;
    cout << ans.singleNumber(nums) << endl;

    return 0;
}