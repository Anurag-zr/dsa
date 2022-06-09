#include <bits/stdc++.h>
using namespace std;

void findCombSum(int ind, vector<int> &ds,vector<int> &nums,int target,vector<vector<int> > &ans){
    if(target == 0){
        ans.push_back(ds);
        
        return;
    }

    for (int i = ind;i<nums.size();i++){
        if(i>ind && nums[i] == nums[i-1]) continue;
        if(nums[i]>target) break;

        ds.push_back(nums[i]);
        findCombSum(i + 1, ds, nums, target - nums[i], ans);
        ds.pop_back();
    }
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 2};
    int target = 4;
    vector<vector<int>> ans;
    vector<int> ds;

    findCombSum(0, ds, nums, target, ans);

    for(auto it: ans){
        for(auto it2:it){
            cout << it2 << " ";
        }
        cout << endl;
    }
}