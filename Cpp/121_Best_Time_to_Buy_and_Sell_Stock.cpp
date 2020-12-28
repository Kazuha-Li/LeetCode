/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

ref:
https://stackoverflow.com/questions/11103652/c-vector-of-pairs-initialization
https://www.cnblogs.com/grandyang/p/4280131.html
*/

#include <iostream>
// #include <utility>  // pair, make_pair
#include <vector>

using namespace std;

class Solution {
   public:
    // 紀錄最小價格，以及最大profit
    // Time = O(n)
    // Space = O(1)
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, min_buy_price = INT32_MAX;
        for (auto price : prices) {
            min_buy_price = min(price, min_buy_price);
            max_profit = max(max_profit, price - min_buy_price);
        }
        return max_profit;
    }
    /*
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0, min_price = prices.at(0);
        for (int i = 1; i < n; i++) {
            int profit = prices[i] - min_price;
            if (prices.at(i) < min_price) min_price = prices[i];
            if (profit > max_profit) max_profit = profit;
        }
        return max_profit;
    }
    */
};

int main() {
    int ary[] = {4, 7, 2, 1, 11};
    vector<int> prices;
    prices.assign(ary, ary + 5);
    Solution res;
    int ans = res.maxProfit(prices);
    cout << ans << endl;

    return 0;
}