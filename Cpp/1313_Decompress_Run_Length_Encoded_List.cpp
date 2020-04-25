#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> decompressRLElist(vector<int>& nums) {
    }
};

vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> answer;

    for (int i = 0; i < nums.size(); i += 2) {
        for (int j = 0; j < nums[i]; j++)
            answer.push_back(nums[i + 1]);
    }

    return answer;
}

int main() {
    vector<int> nums;
    int array[] = {1, 1, 2, 3};
    nums.assign(array, array + 4);

    vector<int> ans;
    ans = decompressRLElist(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}