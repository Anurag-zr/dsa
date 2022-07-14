#include<bits/stdc++.h>
using namespace std;

// memoization tc O(n) ans sc o(n) +O(n);
// int findMaxSum(int ind,vector<int>&dp,vector<int> &nums){
//     if(ind==0) return nums[0];
//     if(ind<0) return 0;
    
//     if(dp[ind]!=-1) return dp[ind];
    
//     int pick = nums[ind] + findMaxSum(ind-2,dp,nums);
//     int notpick = 0+ findMaxSum(ind-1,dp,nums);
    
//     return dp[ind]=max(pick,notpick);
// }

// tabualtion  tc O(n) and sc O(n);

int findMaxSum(vector<int> &nums,int n){
    vector<int> dp(n, -1);
    int pick = INT_MIN;
    int notpick = INT_MIN;
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int j = 2; j < n;j++){
        //pick
         pick = nums[j] + dp[j - 2];
        //not pick
         notpick = 0 + dp[j - 1];

        dp[j] = max(pick, notpick);
    }

    return dp[n - 1];
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n,-1);
    // return findMaxSum(n-1,dp,nums);

    return findMaxSum(nums,n);
}

int main(){
    vector<int> nums = {3, 7, 3, 23, 50,4, 12};
    cout << maximumNonAdjacentSum(nums);
}