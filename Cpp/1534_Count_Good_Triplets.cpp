/*
https://leetcode.com/problems/count-good-triplets/
Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
Where |x| denotes the absolute value of x.

Return the number of good triplets.

Example 1:

Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
Output: 4
Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
Example 2:

Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
Output: 0
Explanation: No triplet satisfies all conditions.
 

Constraints:

3 <= arr.length <= 100
0 <= arr[i] <= 1000
0 <= a, b, c <= 1000
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 暴力法
// Time = O(n^3)
// Space = O(1)
int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (abs(arr[i] - arr[j]) <= a) {
                for (int k = j + 1; k < arr.size(); k++) {
                    if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        cnt++;
                    } else
                        continue;
                }
            }
        }
    }
    return cnt;
}

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums;
    int ary[] = {3, 0, 1, 1, 9, 7};
    nums.assign(ary, ary + 6);

    // arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
    int a = 7, b = 2, c = 3;
    int ans;

    ans = countGoodTriplets(nums, a, b, c);

    cout << ans << endl;

    return 0;
}
