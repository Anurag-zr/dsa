#include <bits/stdc++.h>
using namespace std;

    int findminCost(int ind,vector<int> &cost,vector<int> &dp){
        if(ind == 0) return 0;
        if(ind == 1) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int left = findminCost(ind-1,cost,dp)+cost[ind-1];
        int right = INT_MAX;
        if(ind>1)
         right = findminCost(ind-2,cost,dp)+cost[ind-2];
        
        return dp[ind]= min(left,right);
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
     int n = cost.size();
     vector<int> dp(n+1,-1);
        
     return findminCost(n,cost,dp);   
        
    }


int main(){
    vector<int> cost = {10,15,20};
    cout << minCostClimbingStairs(cost) << endl;
}