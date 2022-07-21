#include<bits/stdc++.h>
using namespace std;



int f(int ind,int weight,vector<int> &w,vector<int> &value,vector<vector<int>> &dp){
    if(weight == 0) return 0;
    if(ind == 0){
        if(w[0] <= weight) return value[0];
        else
            return 0;
    }
    
    if(dp[ind][weight]!=-1) return dp[ind][weight];
    
    int notpick =0 +f(ind-1,weight,w,value,dp);
    int pick = -1e8;
    if(w[ind]<=weight){
        pick = value[ind]+f(ind-1,weight-w[ind],w,value,dp);
    }
    
    return  dp[ind][weight] = max(notpick,pick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int> (maxWeight +1,-1));
    return f(n-1,maxWeight,weight,value,dp);
}

int main(){
    vector<int> weight = {3, 5, 1, 4};
    vector<int> value = {10, 90, 60, 40};
    int maxWeight = 5;

    cout << knapsack(weight, value, 4, maxWeight) << endl;
}