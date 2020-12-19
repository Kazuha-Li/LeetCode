/*
https://leetcode.com/problems/3sum/
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105

ref:
https://www.cnblogs.com/grandyang/p/4481576.html
https://leetcode.com/problems/3sum/discuss/7380/Concise-O(N2)-Java-solution

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// Time = O(n)
// Space = O(n)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    //O(NlogN)
    sort(nums.begin(), nums.end());

    // Time = O(N^2)
    for (int i = 0; i < nums.size(); i++) {
        int l_ptr = i + 1, r_ptr = nums.size() - 1;
        // 如果下一個數跟目前的數相等則跳過，所以要排序
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        // 固定nums[i]
        while (l_ptr < r_ptr) {
            int a = nums[i], b = nums[l_ptr], c = nums[r_ptr];
            int sum = a + b + c;
            // 因為排序過，所以如果sum<0，代表左邊的數太小，所以左邊指針往右移
            if (sum < 0) l_ptr++;
            if (sum > 0) r_ptr--;
            if (sum == 0) {
                ans.push_back({a, b, c});
                // 如果下一個數跟目前的數相等則跳過
                while (l_ptr < r_ptr && nums[l_ptr] == nums[l_ptr + 1]) l_ptr++;
                while (l_ptr < r_ptr && nums[r_ptr] == nums[r_ptr - 1]) r_ptr--;
                l_ptr++, r_ptr--;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums;
    vector<vector<int>> ans;

    int arry[] = {0, 0, 0, 0};
    nums.assign(arry, arry + 4);
    ans = threeSum(nums);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << ans[i][j] << ",";
        }
        cout << endl;
    }

    return 0;
}