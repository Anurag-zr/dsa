#include<bits/stdc++.h>
using namespace std;

   const  int mod = 1e9+7;
    const vector<vector<int>> mapping = {{1},           //a->e
                                         {0,2},         //e->a,i
                                         {0,1,3,4},     //i->a,e,o,u
                                         {2,4},         //o->i,u
                                         {0},          // u->a
                                         {0,1,2,3,4}}; // s -> a,e,i,o,u
    
    int solve(int rem, int prev,vector<vector<int>> &dp){
        if(rem == 0) return 1;
        if(dp[prev][rem]!=-1) return dp[prev][rem];
        
        dp[prev][rem]=0;
        for(auto i:mapping.at(prev)){
          dp[prev][rem]= (dp[prev][rem]+solve(rem-1,i,dp))%mod;    
        }
        
        return dp[prev][rem];
    }
    
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(6,vector<int> (n+1,-1));
        return solve(n,5,dp);
    }

int main(){

    int length = 5;
    cout << countVowelPermutation(length) << endl;
    cout<<countVowelPermutation(2) << endl;
}