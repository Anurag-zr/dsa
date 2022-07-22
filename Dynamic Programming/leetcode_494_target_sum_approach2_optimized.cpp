#include <bits/stdc++.h>
using namespace std;

   
    int subsetSumTarget(int ind,int target,vector<int> &nums,vector<vector<int>> &dp){
        
        if(ind ==0){
            if(target ==0 && nums[0]==0)  return 2; 
            else if(target ==0 && nums[0]!=0) return 1;
            else if(target == nums[0]) return 1;
            else return 0;
        }
        
        if(dp[ind][target] !=-1) return dp[ind][target];
        
        int nottake = subsetSumTarget(ind-1,target,nums,dp);
        int take = 0;
        if(nums[ind]<=target) 
            take = subsetSumTarget(ind-1,target-nums[ind],nums,dp);
        
        return dp[ind][target] = take + nottake;
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        int t_sum =0;
        
        for(auto i:nums) t_sum += i;
        
      
        if((t_sum + target)%2==0 && (t_sum+target)>=0) {
            int n_target = (target+t_sum)/2;
            vector<vector<int>> dp(n,vector<int> (n_target+1,-1));
            return subsetSumTarget(n-1,n_target,nums,dp);
        }
        else return 0;
    }




int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << findTargetSumWays(nums, target) << endl;
}