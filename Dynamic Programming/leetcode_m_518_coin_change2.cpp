#include<bits/stdc++.h>
using namespace std;

     int f(int ind,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(amount == 0) return 1;
        if(ind == 0){
          if(amount%coins[ind]==0) return 1;
            else return 0;
        }     
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int nottake = f(ind -1, amount,coins,dp);
        int take = 0;
        if(coins[ind]<=amount)
            take = f(ind,amount-coins[ind],coins,dp);

        
        return dp[ind][amount] = (take + nottake);
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount + 1,-1));
        
        int ans = f(n-1,amount,coins,dp);
        return ans;
    }

int main(){
    vector<int> coins = {1, 2, 5};
    int target = 5;
    cout << change(target, coins) << endl;
}