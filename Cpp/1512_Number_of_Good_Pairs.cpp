/*
https://leetcode.com/problems/number-of-good-pairs/
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    // Time = O(n)
    // Space = O(n)
    vector<int> cnt(101, 0);
    int ans = 0;
    // 先統計每一個數字個數
    for (int i = 0; i < nums.size(); i++) cnt[nums[i]]++;
    for (int i = 1; i < 101; i++) {
        if (cnt[i] > 1) {
            int n = cnt[i];
            // 知道個數可以直接求good pairs有幾個
            ans += n * (n - 1) / 2;
        }
    }

    // 使用 unordered_map
    // Time = O(n)
    unordered_map<int, int> map;
    int ans = 0;
    for (auto n : nums) {
        map[n]++;
        // 每多一個代表可以跟前n-1個組成 good pairs
        ans += (map[n] - 1);
    }

    return ans;
}

int main(int argc, char const* argv[]) {
    vector<int> nums;
    int ans;
    int arry_A[] = {1, 1, 1, 1};

    nums.assign(arry_A, arry_A + 4);

    ans = numIdenticalPairs(nums);

    cout << "ans = " << ans << endl;

    return 0;
}
