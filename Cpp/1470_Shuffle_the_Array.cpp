#include <iostream>
#include <vector>
using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    // Time = O(n)
    // Space = O(n)
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(nums[i]);
        ans.push_back(nums[n + i]);
    }
    return ans;
}

int main(int argc, char const* argv[]) {
    vector<int> nums;
    vector<int> ans;
    int n = 3;
    int arry_A[] = {2, 5, 1, 3, 4, 7};

    nums.assign(arry_A, arry_A + 6);

    ans = shuffle(nums, n);

    for (auto i = 0; i < ans.size(); i++) {
        cout << ans[i] << ",";
    }
    puts("");

    return 0;
}
