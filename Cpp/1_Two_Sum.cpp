#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

/*
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> findAns;
    map<int, int>::iterator iter;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];
        // map find O(logN)
        iter = findAns.find(diff);

        if (iter != findAns.end()) {
            int found = iter->second;
            ans.push_back(found);
            ans.push_back(i);
            return ans;
        } else
            findAns.insert(pair<int, int>(nums[i], i));
    }
}
*/

// unordered_map
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> dict;
    unordered_map<int, int>::iterator iter;
    vector<int> ans;
    int diff;

    // O(N)
    for (int i = 0; i < nums.size(); i++) {
        diff = target - nums[i];
        // unordered_map find O(1)
        iter = dict.find(diff);
        if (iter != dict.end()) {
            ans.emplace_back(iter->second);
            ans.emplace_back(i);
            // return ans;
        } else
            dict[nums[i]] = i;
    }
    return ans;
}  //Space complexity : O(n).
// The extra space required depends on the number of items stored in the hash table,
// which stores at most n elements.

int main() {
    vector<int> nums;
    vector<int> ans;
    int target = 9;
    int arry[] = {2, 7, 11, 15};
    nums.assign(arry, arry + 4);
    ans = twoSum(nums, target);
    cout << ans[0] << "," << ans[1] << endl;

    return 0;
}