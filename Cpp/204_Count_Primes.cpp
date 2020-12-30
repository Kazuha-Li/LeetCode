/*
https://leetcode.com/problems/count-primes/
Count the number of prime numbers less than a non-negative number, n.

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106

ref:
https://www.cnblogs.com/grandyang/p/4462810.html
https://www.geeksforgeeks.org/how-is-the-time-complexity-of-sieve-of-eratosthenes-is-nloglogn/
*/

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    // sieve of Eratosthenes，用一個陣列來記錄是否為 prime
    // 如果遇到 prime 就把這個質數的所有倍數都標成 false，最後統計 true 的個數
    // 注意：只需要檢查到 根號n 即可
    // Time = O(nlog(logn))
    // Space = O(n)
    int countPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        // 用 array 速度會比 vector 快很多
        // bool isPrime[n+1];
        // memset(isPrime, true, sizeof(isPrime));

        int cntprimes = 0;
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i] == true) {
                for (int j = i + i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i < n; i++) {
            if (isPrime[i] == true) cntprimes++;
        }
        return cntprimes;
    }
};

int main() {
    int n = 100;
    Solution res;

    cout << res.countPrimes(n) << endl;

    return 0;
}