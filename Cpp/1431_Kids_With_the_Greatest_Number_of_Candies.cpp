/*
https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ans;
    // int Max = *std::max_element(candies.begin(), candies.end());
    // cout << "Max = " << Max << endl;

    //O(N)
    int Max = 0;
    for (int i = 0; i < candies.size(); i++) {
        if (candies[i] > Max) Max = candies[i];
    }
    //O(N)
    for (int i = 0; i < candies.size(); i++) {
        if (candies[i] + extraCandies + 1 > Max)
            ans.push_back(true);
        else
            ans.push_back(false);
    }

    return ans;
}

int main() {
    vector<int> candies;
    vector<bool> ans;

    int arry[] = {4, 2, 1, 1, 2};
    candies.assign(arry, arry + 5);
    int extraCandies = 1;

    ans = kidsWithCandies(candies, extraCandies);

    for (auto i = 0; i < ans.size(); i++) {
        cout << ans[i] << ",";
    }
    puts("");

    return 0;
}