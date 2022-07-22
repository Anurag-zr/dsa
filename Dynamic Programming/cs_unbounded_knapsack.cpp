#include <bits/stdc++.h>
using namespace std;

//memoization solution

int f(int ind,int w,vector<int> &profit,vector<int> &weight,vector<vector<int>> &dp){
    if(w==0) return 0;
    if(ind==0){
        if(weight[0]<=w) return w/weight[0] * profit[0];
        else return 0;
    }
    
    if(dp[ind][w]!=-1) return dp[ind][w];
    
    int nottake = 0+ f(ind-1,w,profit,weight,dp);
    int take =0;
    if(weight[ind]<=w)
        take = profit[ind] + f(ind,w-weight[ind],profit,weight,dp);
    
    return dp[ind][w]=max(take,nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int> (w+1,-1));
    return f(n-1,w,profit,weight,dp);
}

//tabulation solution

int unboundedKnapsackTabuSol(int n,int w,vector<int> &profit,vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    for (int i = 0; i < n - 1;i++)
        dp[i][0] = 0;

    for (int wt = weight[0]; wt <= w;wt++)
        dp[0][wt] = wt / weight[0] * profit[0];

    for (int ind = 1; ind < n;ind++){
        for (int wt = 0; wt <= w;wt++){
             int nottake = 0+ dp[ind-1][wt];
             int take =0;
             if(weight[ind]<=wt)
                 take = profit[ind] + dp[ind][wt-weight[ind]];

             dp[ind][wt] = max(take, nottake);
        }
    }

    return dp[n - 1][w];
}

int unboundedKnapsack1DSOsol(int n,int w,vector<int> &profit,vector<int> &weight){
        vector<int> cur(w+1,-1);
   for (int wt = weight[0]; wt <= w;wt++)
        cur[wt] = wt/ weight[0] * profit[0];
    
    cur[0] =0;
    
    for (int ind = 1; ind < n;ind++){
        for (int wt = 1; wt<=w;wt++){
             int nottake = 0+ cur[wt];
             int take = 0;
             if(weight[ind]<=wt)
                 take = profit[ind] + cur[wt-weight[ind]];

             cur[wt] = max(take, nottake);
        }
    }
    
    return cur[w];
}

int main(){
    vector<int> profit = {5,11,13};
    vector<int> weight = {2,4,6};
    int w = 10;
    int n = 3;
    cout << unboundedKnapsack(n, w, profit, weight) << endl;
    cout << unboundedKnapsackTabuSol(n, w, profit, weight) << endl;
    cout << unboundedKnapsack1DSOsol(n, w, profit, weight) << endl;
}
