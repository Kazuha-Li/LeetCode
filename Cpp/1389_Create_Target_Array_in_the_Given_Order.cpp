/*
https://mropengate.blogspot.com/2015/07/cc-vector-stl.html
http://www.cplusplus.com/reference/vector/vector/insert/
https://leetcode.com/problems/create-target-array-in-the-given-order/
Given two arrays of integers nums and index. Your task is to create target array under the following rules:

Initially target array is empty.
From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
Repeat the previous step until there are no elements to read in nums and index.
Return the target array.

It is guaranteed that the insertion operations will be valid.

 

Example 1:

Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]
Explanation:
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    // vector insert Time = O(n)
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        ans.insert(ans.begin() + index[i], nums[i]);
    }
    return ans;
}

int main(int argc, char const* argv[]) {
    vector<int> nums;
    vector<int> index;
    vector<int> ans;
    int arry_A[] = {0, 1, 2, 3, 4};
    int arry_B[] = {0, 1, 2, 2, 1};

    nums.assign(arry_A, arry_A + 5);
    index.assign(arry_B, arry_B + 5);

    ans = createTargetArray(nums, index);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    puts("");

    return 0;
}
