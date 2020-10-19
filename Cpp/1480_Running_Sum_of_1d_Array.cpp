#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> ans;

    // Time = O(n)
    // Space = O(n)
    // ans.push_back(nums[0]);
    // for (int i = 1; i < nums.size(); i++) {
    //     ans.push_back(ans[i - 1] + nums[i]);
    // }
    // return ans;
    /*
    int n = nums.size();
    ans.reserve(n);
    // 使用reserve之後還是要用push_back
    // 不能用ans[i] = ans[i - 1] + nums[i]
    ans.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
        ans.push_back(ans[i - 1] + nums[i]);
    }
    return ans;
    */

    // Time = O(n)
    // Space = O(1)
    for (int i = 1; i < nums.size(); i++) {
        nums[i] = nums[i - 1] + nums[i];
    }
    return nums;
}

int main(int argc, char const* argv[]) {
    vector<int> nums;
    vector<int> ans;
    int arry[] = {1, 2, 3, 4};
    nums.assign(arry, arry + 4);

    ans = runningSum(nums);
    for (auto i = 0; i < ans.size(); i++) {
        cout << ans[i] << ",";
    }
    puts("");

    return 0;
}
