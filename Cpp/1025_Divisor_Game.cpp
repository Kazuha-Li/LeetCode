/*
https://leetcode.com/problems/divisor-game/
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.


Example 1:

Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:

Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
 

Note:

1 <= N <= 1000

ref:
https://leetcode.com/problems/divisor-game/discuss/274606/JavaC%2B%2BPython-return-N-2-0
*/

#include <string.h>

#include <iostream>

using namespace std;
class Solution {
   public:
    // 數學歸納法
    // Time = O(1)
    /*
    bool divisorGame(int N) {
        return N%2 == 0;
    }
    */
    // DP
    // Time = O(N^2)
    // Space = O(N)
    bool divisorGame(int N) {
        bool dp[N + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 2; i < N + 1; i++) {
            for (int j = 0; j * j < i; j++) {
                // 符合題目條件 N%x == 0 然後因為這次取完換成是對方先手的情況
                // 所以找 dp[i-j] == false 的情況
                if (i % j == 0 && !dp[i - j]) dp[i] = true;
            }
        }
        return dp[N];
    }
};

int main() {
    return 0;
}