/*

[1,2,3] n=3,possible permutation n!=6

In other solution we used map(data structure) freq to find
whether no. is considered or not which result in extra space complexity.
now we give more optimized solution.


*/

#include <bits/stdc++.h>
using namespace std;


 void findPermutation(int ind,vector<int> &nums,vector<vector<int>> &ans){
    if(ind==nums.size()){
        ans.push_back(nums);
        return;
    }

    for (int i = ind; i < nums.size(); i++){
        swap(nums[ind], nums[i]);
        findPermutation(ind + 1, nums, ans);
        swap(nums[ind], nums[i]);
    }
 }

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;

    findPermutation(0,nums,ans);

    for(auto it:ans){
        for(auto it1:it){
            cout << it1 << " ";
        }
        cout << endl;
    }
}