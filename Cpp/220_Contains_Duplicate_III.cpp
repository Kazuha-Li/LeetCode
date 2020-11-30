/*
https://leetcode.com/problems/contains-duplicate-ii/
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
https://medium.com/leetcode-%E6%BC%94%E7%AE%97%E6%B3%95%E6%95%99%E5%AD%B8/054-leetcode-219%E6%BC%94%E7%AE%97%E6%B3%95-contains-duplicate-iii-%E5%8C%85%E5%90%AB%E9%87%8D%E8%A4%87%E5%80%BC-iii-a721bd96f672
https://magiclen.org/bucket-sort/
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// 使用 map 另外維護一個指標 j 確保 map 內部的元素只有 k 個
// Time = O(nlogk)
// Space = O(k)
// https://www.cnblogs.com/grandyang/p/4545261.html
/*
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();
    int j = 0;
    map<long long, int> dict;
    map<long long, int>::iterator lower;
    for (int i = 0; i < n; i++) {
        // 維持 map 內部的元素都只有 k 個 這樣查找時間為 logk
        if (i - j > k) {
            dict.erase(nums[j]);
            j++;
        }
        // 因為 map 內部是有序，lower_bound 會回傳 大於等於 nums[i] - t 的第一個數的指標
        // 之後再確認相減的絕對值是否小於 t ，因為是有序的，nums[i] + t 一定會在 nums[i] - t 的右邊
        // 所以檢查絕對值即可
        lower = dict.lower_bound((int64_t)nums[i] - t);
        if (lower != dict.end() && abs((*lower).first - nums[i]) <= t) return true;
        dict[nums[i]] = i;
    }
    return false;
}
*/

//https://leetcode.com/problems/contains-duplicate-iii/discuss/824578/C%2B%2B-O(N)-time-complexity-or-Explained-or-Buckets-or-O(K)-space-complexity
// 使用 bucket sort
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();
    unordered_map<int, int> buckets;
    // t+1 為一個 bucket
    for (int i = 0; i < n; i++) {
        // 維持 bucket 數量不超過 k 個
        if (buckets.size() > k) {
            int erase_idx = nums[i - k - 1] / ((long)t + 1);
            if (nums[i - k - 1] < 0) erase_idx--;
            buckets.erase(erase_idx);
        }
        int index = nums[i] / ((long long)t + 1);
        // For negative numbers, we need to decrement bucket by 1
        // to ensure floor division.
        // For example, -1/2 = 0 but -1 should be put in Bucket[-1].
        // Therefore, decrement by 1.
        if (nums[i] < 0) index--;
        if (buckets.find(index) == buckets.end()) {
            // 檢查前後是否有符合條件的數存在
            if (buckets.find(index + 1) != buckets.end() && (long)buckets[index + 1] - nums[i] <= t) return true;
            if (buckets.find(index - 1) != buckets.end() && (long)nums[i] - buckets[index - 1] <= t) return true;
            buckets[index] = nums[i];
        } else
            return true;
    }

    return false;
}

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums;
    int ary[] = {2147483647, -1, 2147483647};
    nums.assign(ary, ary + 3);
    int k = 2;
    int t = 2147483647;
    bool ans;
    ans = containsNearbyAlmostDuplicate(nums, k, t);
    cout << ans << endl;

    return 0;
}
