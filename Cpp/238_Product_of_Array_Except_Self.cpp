/*
https://leetcode.com/problems/product-of-array-except-self/

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

ref:
https://leetcode.com/problems/product-of-array-except-self/solution/


*/

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    /*
    // Apporch 1:
    // 關鍵：前面所有數的products * 後面所有數的products
    // 利用兩個array 一個紀錄由左到右每一格的累進products，另一個由右到左
    // Time = O(n)
    // Space = O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> forward(n, 1), backward(n, 1), ans(n);
        for (int i = 0; i < n - 1; i++) {
            forward[i + 1] = forward[i] * nums[i];
        }
        for (int j = n - 1; j > 0; j--) {
            backward[j - 1] = backward[j] * nums[j];
        }
        for (int k = 0; k < n; k++) {
            ans[k] = forward[k] * backward[k];
        }
        return ans;
    }
    */
    // Apporch 2:
    // 空間優化 Space optimization
    // 前半段演算法與上面相同
    // 後半段只用一個變量累進 (use a variable to keep track of the running product of elements to the right)
    // Time = O(n)
    // Space = O(1) (The output array does not count as extra space for the purpose of space complexity analysis)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 0; i < n - 1; i++) {
            res[i + 1] = res[i] * nums[i];
        }
        int back = 1;
        for (int j = n - 1; j > 0; j--) {
            back *= nums[j];
            res[j - 1] *= back;
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    return 0;
}
