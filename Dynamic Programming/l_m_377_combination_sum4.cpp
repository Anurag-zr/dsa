#include <bits/stdc++.h>
using namespace std;

    int findCombinations(vector<int> &nums,int target,vector<int> &dp){
        if(target == 0) return 1;
        if(dp[target]!=-1) return dp[target];
        
        int ans =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target){
               ans+=findCombinations(nums,target-nums[i],dp);
            }
        }
        
        return dp[target]=ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return findCombinations(nums,target,dp);
    }

int main(){
    vector<int> nums = {1,2,3};
    int target = 4;
    // ans =7;
    //1,1,1,1
    //1,1,2
    //1,2,1
    //2,1,1
    //1,3
    //3,1
    //2,2
    cout << combinationSum4(nums, target) << endl;
}