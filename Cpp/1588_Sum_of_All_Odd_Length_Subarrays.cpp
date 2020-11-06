/*
https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array.

Return the sum of all odd-length subarrays of arr.

 

Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
*/
#include <iostream>
#include <vector>
using namespace std;

int sumOddLengthSubarrays(vector<int>& arr) {
    int sum = 0;
    int tmp = 0;
    int n = arr.size();
    /*
    // Time = O(n^2)
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                tmp = arr[i];
                sum += tmp;
                continue;
            } else if ((i + j) % 2 == 0) {
                tmp += arr[j];
                sum += tmp;
            } else {
                tmp += arr[j];
            }
        }
    }*/
    // Time = O(n)
    // Space = O(1)
    // 當我們取第arr[i]個，左邊可以取 0~i 個共有(i+1)種選擇
    // 右邊可以取 0 ~ n-1-i 個，共有(n-i)種選擇
    // 所以 arr[i] 總共會被算到的次數為 (i+1)(n-i) 次
    // 其中奇數長度有 ((i+1)(n-i)+1)/2 次
    for (int i = 0; i < n; i++) {
        tmp = arr[i] * (((i + 1) * (n - i) + 1) / 2);
        sum += tmp;
    }

    return sum;
}

int main(int argc, char const* argv[]) {
    vector<int> arr;
    int ary[] = {1, 4, 2, 5, 3};
    arr.assign(ary, ary + 5);
    int ans;
    ans = sumOddLengthSubarrays(arr);

    cout << "ans = " << ans << endl;

    return 0;
}
