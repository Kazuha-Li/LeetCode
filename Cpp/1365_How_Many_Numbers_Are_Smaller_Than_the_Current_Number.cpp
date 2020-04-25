#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    }
};

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    // 使用兩個array 一個用來紀錄數字出現的頻率
    // 另一個用來紀錄累計數量 prefix sum
    // 時間如下，所以總共為O(N)
    vector<int> amount(101, 0);
    vector<int> grand_amount(101, 0);
    // O(N)
    for (int i = 0; i < nums.size(); i++) {
        amount[nums[i]]++;
    }

    grand_amount[0] = amount[0];
    // O(N)
    for (int i = 1; i < 101; i++) {
        grand_amount[i] = grand_amount[i - 1] + amount[i];
    }

    // O(N)
    for (int i = 0; i < nums.size(); i++) {
        // cout << nums[i] << endl;
        if (nums[i] != 0)
            nums[i] = grand_amount[nums[i] - 1];
        // cout << nums[i] << endl;
    }
    return nums;
}

int main() {
    vector<int> nums;
    int arry[] = {5, 0, 10, 0, 10, 6};
    nums.assign(arry, arry + 6);

    smallerNumbersThanCurrent(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ",";
    }
    cout << endl;
    return 0;
}