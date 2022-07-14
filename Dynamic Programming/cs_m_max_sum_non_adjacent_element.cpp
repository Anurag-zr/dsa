#include<bits/stdc++.h>
using namespace std;

int findMaxSum(int ind,vector<int>&dp,vector<int> &nums){
    if(ind==0) return nums[0];
    if(ind<0) return 0;
    
    if(dp[ind]!=-1) return dp[ind];
    
    int pick = nums[ind] + findMaxSum(ind-2,dp,nums);
    int notpick = 0+ findMaxSum(ind-1,dp,nums);
    
    return dp[ind]=max(pick,notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,-1);
    return findMaxSum(n-1,dp,nums);
}

int main(){
    vector<int> nums = {3, 7, 3, 23, 50,4, 12};
    cout << maximumNonAdjacentSum(nums);
}