/*
https://leetcode.com/problems/coin-change/

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

ref:
https://www.cnblogs.com/grandyang/p/5138186.html

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution_DP {
   public:
    // Time = O(mn) --> m = amount + 1, n = coins.size()
    // Space = O(m)
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        // cout<<dp.back()<<endl;
        return (dp.back() > amount) ? -1 : dp.back();
    }
};
/* 
test case

[411,412,413,414,415,416,417,418,419,420,421,422]
9864

使用brute force剪枝的方式會TLE

*/