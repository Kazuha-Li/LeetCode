/*
References
https://leetcode.com/problems/sort-array-by-parity/
http://www.cplusplus.com/reference/algorithm/swap/
https://www.techiedelight.com/concatenate-two-vectors-cpp/
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
    int l = 0, r = A.size()-1;
    while(r>l){
        if(A[l]%2 == 1 && A[r]%2 == 0){
            // std::swap(A[l],A[r]);
            int tmp = A[l];
            A[l] = A[r];
            A[r] = tmp;
        }
        if(A[l]%2 == 0) l++;
        if(A[r]%2 == 1) r--;
    }
    return A;
}

int main() {
    vector<int> nums;
    vector<int> ans;

    int arry[] = {3,1,2,4};
    nums.assign(arry, arry + 4);

    ans = sortArrayByParity(nums);

    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }puts("");

    return 0;
}