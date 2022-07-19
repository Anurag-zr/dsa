#include<bits/stdc++.h>
using namespace std;


//memoization solution
bool f(int ind, int target, vector<int> &arr,vector<vector<int>> &dp){
    if(target == 0) return true;
    if(ind == 0) return (arr[0]==target);
    
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool nottake = f(ind-1,target,arr,dp);
    bool take = false;
    if(arr[ind]<=target){
        take = f(ind-1,target-arr[ind],arr,dp);
    }
    
    return dp[ind][target]=(take | nottake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return f(n-1,k,arr,dp);
}

//memoization


//tabulation solution

bool tabulationSol(int n,int k,vector<int> arr){
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n;i++){
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for (int ind = 1; ind < n;ind++){
        for (int target = 1; target <= k;target++){
            bool nottake = dp[ind - 1][target];
            bool take = false;
            if(arr[ind]<=target){
                take = dp[ind-1][target-arr[ind]];
            }


            dp[ind][target]= (take | nottake);
        }
    }

    return dp[n - 1][k];
}

//space optimization

bool spaceOptimizationSol(int n,int k,vector<int> arr){
    vector<bool> prev(k + 1, false);
    vector<bool> cur(k+1,false);

    prev[arr[0]] = true;
    prev[0] = true;

    for (int ind = 0; ind < n;ind++){
        cur[0] = true;
        for (int target = 1; target <= k;target++){
            bool nottake = prev[target];
            bool take = false;
            if(arr[ind]<=target){
                take = prev[target - arr[ind]];
            }

            cur[target] = (take | nottake);
        }

        prev = cur;
    }

    return prev[k];
}


int main(){
    vector<int> arr{3, 1, 2, 4, 5, 9};
    int k = 15;
    int n = arr.size();

    // cout << subsetSumToK(n, k, arr) << endl;

    // cout << tabulationSol(n, k, arr) << endl;

    cout<< spaceOptimizationSol(n,k,arr) << endl;
}