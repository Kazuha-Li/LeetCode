/*
https://leetcode.com/problems/richest-customer-wealth/
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

Example 1:

Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.
Example 2:

Input: accounts = [[1,5],[7,3],[3,5]]
Output: 10
Explanation: 
1st customer has wealth = 6
2nd customer has wealth = 10 
3rd customer has wealth = 8
The 2nd customer is the richest with a wealth of 10.
Example 3:

Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]
Output: 17
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Time = O(mn)
// Space = O(1)
int maximumWealth(vector<vector<int>>& accounts) {
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < accounts.size(); i++) {
        for (int j = 0; j < accounts[i].size(); j++) {
            sum += accounts[i][j];
        }
        // if (sum > ans) ans = sum;
        ans = max(sum, ans);
        sum = 0;
    }
    return ans;
}

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // vector<int> nums;
    // int ary[] = {7, 7, 5, 7, 5, 7, 5, 7, 5, 5, 7, 7, 7, 4, 5, 7};
    // nums.assign(ary, ary + 16);
    vector<vector<int>> accounts{
        {2, 8, 7},
        {7, 1, 3},
        {1, 9, 5}};

    int ans;
    ans = maximumWealth(accounts);

    cout << "ans = " << ans << endl;

    return 0;
}
