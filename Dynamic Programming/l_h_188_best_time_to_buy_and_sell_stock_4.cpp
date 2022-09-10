#include<bits/stdc++.h>
using namespace std;

 // TLE Approach using recursion 
    // int helper(int ind,bool canBuy,int k,vector<int> &prices,int boughtItemInd,int profit){
    //     if(ind == prices.size()){
    //         if(boughtItemInd!=-1){
    //             return profit+prices[boughtItemInd];
    //         }
            
    //         return profit;
    //     }
        
    //     if(k<=0 && canBuy==true) return profit;
        
        
        
    //     if(canBuy){
    //         int buy = helper(ind+1,false,k-1,prices,ind,profit-prices[ind]);
            
    //         int notBuy = helper(ind+1,true,k,prices,-1,profit);
            
    //         profit =max(buy,notBuy);
    //     }
        
    //     else{
    //         int sell = INT_MIN;
    //         if(prices[ind]-prices[boughtItemInd]>=0){
    //              sell = helper(ind+1,true,k,prices,-1,profit+prices[ind]);
    //         }
            
    //         int notSell = helper(ind+1,false,k,prices,boughtItemInd,profit);
            
    //         profit =max(sell,notSell);
    //     }
        
        
    //     return profit;
    // }
    
    // int maxProfit(int k, vector<int>& prices) {
    //     bool canBuy =true; //intially we can buy
    //     int boughtItemInd=-1; //store index of bought item
    //     int profit =0; //intially 0 profit
    //      profit = helper(0,canBuy,k,prices,boughtItemInd,profit);
        
    //     return profit;
    // }


//memoization approach        
    int helper(int ind,bool canBuy,int k,vector<int> &prices,        vector<vector<vector<int>>> &dp){
        
        if(ind == prices.size()){
            return 0;
        }
        
        if(k<=0 && canBuy==true) return 0;
        
        if(dp[ind][canBuy][k]!=-1) return dp[ind][canBuy][k];
        
        
        int profit;
        
        if(canBuy){
            int buy =-prices[ind]+helper(ind+1,false,k-1,prices,dp);
            
            int notBuy =0+ helper(ind+1,true,k,prices,dp);
            
            profit =max(buy,notBuy);
        }
        
        else{
            
            int sell = prices[ind]+helper(ind+1,true,k,prices,dp);

            int notSell =0+ helper(ind+1,false,k,prices,dp);
            
            profit =max(sell,notSell);
        }
        
        
        return dp[ind][canBuy][k]=profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        bool canBuy =true; //intially we can buy
        int boughtItemInd=-1; //store index of bought item
        
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (2,vector<int> (k+1,-1)));
        int profit = helper(0,canBuy,k,prices,dp);
        
        return profit;
    }


int main(){
// Input: k = 2, prices = [3,2,6,5,0,3]
vector<int> prices = {3, 2, 6, 5, 0, 3};
int k = 2;
cout << maxProfit(k, prices) << endl;
}