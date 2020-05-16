/*
https://leetcode.com/problems/non-decreasing-array/
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool checkPossibility(vector<int>& nums) {
    bool modify = false;
    for (int i = 0; i < nums.size() - 1; i++) {
        // cout << "i = " << i << endl;
        if (nums[i] > nums[i + 1]) {
            // cout << nums[i] << endl;
            // 如果已經修改過則return false
            if (modify)
                return false;
            else {
                modify = true;
                // 想成可以任意修改一個數的數值
                // {4,2,3} >> {2,2,3}
                // {1,4,2,3} >> {1,2,2,3}
                if (i == 0 || nums[i - 1] < nums[i + 1])
                    nums[i] = nums[i + 1];
                // {1,4,2,5} >> {1,4,4,5}
                else
                    nums[i + 1] = nums[i];
            }
        }
    }
    return true;
}

int main() {
    vector<int> nums;
    bool ans;

    int arry[] = {4, 2, 3};
    nums.assign(arry, arry + 3);

    ans = checkPossibility(nums);
    cout << ans << endl;

    return 0;
}