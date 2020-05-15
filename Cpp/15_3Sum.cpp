/*
https://leetcode.com/problems/3sum/
https://github.com/azl397985856/leetcode/blob/master/problems/15.3-sum.md
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

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