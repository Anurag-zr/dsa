#include <bits/stdc++.h>
using namespace std;

//this approach work for memoization table for negative indices value
//use map<pair<int,int>,int> instead of vector<vector<int>>

//here, target can vary from -t_sum+target <= target <= t_sum + target

int f(int ind,int target,vector<int> &arr,map<pair<int,int>,int> &dp){
    if(ind==-1){
        if(target==0) return 1;
        else return 0;
    }
    
         if(dp.find(make_pair(ind, target)) != dp.end()){
            return dp[make_pair(ind, target)];
        }

    
    int neg = f(ind-1,target+arr[ind],arr,dp);
    int pos = f(ind-1,target-arr[ind],arr,dp);
    
    return dp[make_pair(ind,target)]=neg + pos;
}
    
    int findTargetSumWays(vector<int>& nums, int target) {
      int n= nums.size();
      map<pair<int,int>,int> dp;
      return f(n-1,target,nums,dp);
    }



int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << findTargetSumWays(nums, target) << endl;
}