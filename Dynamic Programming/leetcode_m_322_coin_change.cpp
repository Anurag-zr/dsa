#include <bits/stdc++.h>
using namespace std;

    int f(int ind,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(amount == 0) return 0;
        if(ind == 0){
          if(amount%coins[ind]==0) return amount/coins[ind];
            else return 1e8;
        }     
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int nottake = 0+f(ind -1, amount,coins,dp);
        int take = 1e8;
        if(coins[ind]<=amount)
            take = 1+ f(ind,amount-coins[ind],coins,dp);

        
        return dp[ind][amount] = min(take,nottake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount + 1,-1));
        
        int ans = f(n-1,amount,coins,dp);
        if(ans != 1e8) return ans;
        return -1;
    }

int main(){

    vector<int> coins = {3, 7};
    int amount = 42;
    cout << coinChange(coins, amount) << endl;
}