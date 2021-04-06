/*
https://leetcode.com/problems/sort-array-by-parity/

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000

References
https://leetcode.com/problems/sort-array-by-parity/
http://www.cplusplus.com/reference/algorithm/swap/
https://www.techiedelight.com/concatenate-two-vectors-cpp/
https://leetcode.com/problems/sort-array-by-parity/discuss/170734/C%2B%2BJava-In-Place-Swap
https://www.cnblogs.com/grandyang/p/11173513.html

*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
// Time = O(N) Space = O(N)
vector<int> sortArrayByParity(vector<int>& A) {
    vector<int> even;
    vector<int> odd;
    for(int i = 0; i < A.size(); i++){
        if(A[i] % 2 == 0) even.emplace_back(A[i]);
        else odd.emplace_back(A[i]);
    }
    even.insert(even.end(),odd.begin(),odd.end());
    return even;
}
*/

// Time = O(N) Space = O(1)
vector<int> sortArrayByParity(vector<int>& A) {
    int l = 0, r = A.size() - 1;
    while (r > l) {
        if (A[l] % 2 == 1 && A[r] % 2 == 0) {
            // std::swap(A[l],A[r]);
            // swap method 1
            // int tmp = A[l];
            // A[l] = A[r];
            // A[r] = tmp;
            // swap method 2
            A[l] = A[l] ^ A[r];
            A[r] = A[l] ^ A[r];
            A[l] = A[l] ^ A[r];
        }
        if (A[l] % 2 == 0) l++;
        if (A[r] % 2 == 1) r--;
    }
    return A;
}

int main() {
    vector<int> nums;
    vector<int> ans;

    int arry[] = {3, 1, 2, 4};
    nums.assign(arry, arry + 4);

    ans = sortArrayByParity(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    puts("");

    return 0;
}