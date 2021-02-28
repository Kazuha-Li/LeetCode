/* 
https://leetcode.com/problems/monotonic-array/

An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

 

Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true
 

Note:

1 <= A.length <= 50000
-100000 <= A[i] <= 100000

ref:
https://leetcode.com/problems/monotonic-array/solution/
https://www.cnblogs.com/grandyang/p/10961560.html

*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    /*
    // Approach 1: Two Pass
    // Time = O(n)
    // Space = O(1)
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool isMono = true;
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                isMono = false;
                break;
            }
        }
        if (isMono)
            return true;
        else {
            for (int j = 1; j < n; j++) {
                if (A[j] < A[j - 1]) return false;
            }
        }
        return true;
    }
    */
    // 先判斷是否為 increasing
    // 如果是increasing 但是 A[i] >A[i+1] 則 return false，反之
    // Time = O(n)
    // Space = O(1)
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool isIncreasing = (A[0] <= A[n - 1]);
        for (int i = 0; i < n - 1; i++) {
            if (isIncreasing && A[i] > A[i + 1])
                return false;
            else if (!isIncreasing && A[i] < A[i + 1])
                return false;
        }
        return true;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
