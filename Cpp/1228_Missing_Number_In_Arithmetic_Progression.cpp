/*
https://leetcode.com/problems/missing-number-in-arithmetic-progression/

In some array arr, the values were in arithmetic progression: the values arr[i+1] - arr[i] are all equal for every 0 <= i < arr.length - 1.

Then, a value from arr was removed that was not the first or last value in the array.

Return the removed value.

 

Example 1:

Input: arr = [5,7,11,13]
Output: 9
Explanation: The previous array was [5,7,9,11,13].
Example 2:

Input: arr = [15,13,12]
Output: 14
Explanation: The previous array was [15,14,13,12].
 

Constraints:

3 <= arr.length <= 1000
0 <= arr[i] <= 10^5

ref:
https://leetcode.com/problems/missing-number-in-arithmetic-progression/solution/
https://leetcode.com/problems/missing-number-in-arithmetic-progression/discuss/408474/JavaC%2B%2BPython-Arithmetic-Sum-and-Binary-Search

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// Time = O(log n)
// Space = O(1)
class Solution_binary_search {
   public:
    int missingNumber(vector<int>& arr) {
        int n = (int)arr.size();
        int diff = (arr.back() - arr.front()) / n;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr[mid] == arr.front() + diff * mid)  //代表左半邊是正確的
                l = mid + 1;
            else
                r = mid;
        }
        // cout<< "l = "<<l <<", diff = "<< diff<<endl;
        return arr.front() + diff * l;
    }
};
// Time = O(n)
// Space = O(1)
class Solution_sum {
   public:
    int missingNumber(vector<int>& arr) {
        int sum = 0;
        for (int a : arr) sum += a;
        int n = (int)arr.size();
        int total = (arr[0] + arr[n - 1]) * (n + 1) / 2;
        return total - sum;
    }
};