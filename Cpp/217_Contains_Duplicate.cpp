/*
https://leetcode.com/problems/contains-duplicate/
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
https://leetcode.com/problems/contains-duplicate/solution/
http://www.cplusplus.com/reference/algorithm/unique/
https://www.geeksforgeeks.org/stdunique-in-cpp/
http://www.cplusplus.com/reference/algorithm/sort/
https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 使用 unordered_map 先 find num 是否在 dict 中
// 若不在 dict 中則將 num 加入到 dict 中
// 若 num 已經存在 dict 中，則 return true
// Time = O(n)
// Space = O(n)
// bool containsDuplicate(vector<int>& nums) {
//     unordered_map<int, int> dict;
//     for (auto num : nums) {
//         if (dict.find(num) == dict.end())
//             dict[num] = 1;
//         else
//             return true;
//     }
//     return false;
// }

// 先對 nums 進行 sort
// 使用 unique 找出是否有重複 該函數會回傳第一個重複元素的指標位置
// Time = O(nlogn)
// Space = O*(1)
bool containsDuplicate(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sort(nums.begin(), nums.end());
    vector<int>::iterator it;
    it = unique(nums.begin(), nums.end());
    if (it == nums.end())
        return false;
    else
        return true;
}

int main(int argc, char const* argv[]) {
    vector<int> nums;
    int ary[] = {0, 0, 0};
    nums.assign(ary, ary + 3);
    bool ans;
    ans = containsDuplicate(nums);
    cout << ans << endl;

    return 0;
}
