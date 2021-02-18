/*
https://leetcode.com/problems/min-cost-climbing-stairs/

On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].

ref:
https://leetcode.com/problems/min-cost-climbing-stairs/solution/
https://www.cnblogs.com/grandyang/p/8343874.html

*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    /*
    // DP 
    // dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]
    // Time = O(n)
    // Space = O(1)
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        int dp[n];
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return dp[n - 1];
    }
    */
    // DP 空間優化  Optimizing Space complexity
    // 因為只會使用到前兩格的資訊
    // Space = O(1)
    int minCostClimbingStairs(vector<int>& cost) {
        int f1 = cost[0], f2 = cost[1], n = cost.size();
        if (n == 2) return min(f1, f2);
        for (int i = 2; i < n; i++) {
            int f0 = cost[i] + min(f1, f2);
            f1 = f2;
            f2 = f0;
        }
        return min(f1, f2);
    }
};

int main(int argc, char const* argv[]) {
    Solution res;
    vector<int> cost{1, 100};
    cout << res.minCostClimbingStairs(cost) << endl;
    return 0;
}
