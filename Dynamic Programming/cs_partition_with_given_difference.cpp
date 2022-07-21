#include<bits/stdc++.h>
using namespace std;

 int m = (int)1e9 +7;

int countSubset(int ind,vector<int> &arr,int target,vector<vector<int>> &dp){
    
    if(ind==0){
        if(target ==0 && arr[0]==0) return 2;
        if(target == arr[0] || target==0) return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1) return dp[ind][target];
    
    int nottake = countSubset(ind-1,arr,target,dp);
    int take=0;
    if(arr[ind]<=target)
        take = countSubset(ind-1,arr,target-arr[ind],dp);
    
    return dp[ind][target] = (take + nottake)%m;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int t_sum =0;
    for(auto i:arr) t_sum+=i;
    
    int target = (t_sum + d)/2;
    
    vector<vector<int>> dp(n,vector<int> (target+1,-1));
    if((t_sum+d)%2==0)
    return countSubset(n-1,arr,target,dp);
    else
        return 0;
}




int main(){
    vector<int> arr = {0, 0, 3, 6};
    int n = arr.size();
    int diff = 3;
    cout << countPartitions(n, diff, arr) << endl;
}