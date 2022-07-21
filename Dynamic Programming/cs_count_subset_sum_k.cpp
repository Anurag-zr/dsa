#include<bits/stdc++.h>
using namespace std;


//memoization solution 

// int countSubset(int ind,vector<int> &num,int target,vector<vector<int>> &dp){
//     if(target==0) return 1;
//     if(ind==0)  return (num[0]==target);
    
//     if(dp[ind][target]!=-1) return dp[ind][target];
    
//     int nottake = countSubset(ind-1,num,target,dp);
//     int take = 0;
//     if(num[ind]<=target)
//         take = countSubset(ind-1,num,target-num[ind],dp);
    
//     return dp[ind][target] = take + nottake;
// }

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
//     vector<vector<int>> dp(n,vector<int> (tar+1,-1));
//     return countSubset(n-1,num,tar,dp);
    
    //space optimization solution
    vector<int> prev(tar+1,0);
    vector<int> cur(tar+1,0);
    
    prev[0]=cur[0]=1;
    if(num[0]<=tar) prev[num[0]]=1;
    
    for(int ind = 1;ind<n;ind++){
        for(int target = 0;target<=tar;target++){
            int nottake = prev[target];
            int take = 0;
            if(num[ind]<=target)
                take = prev[target-num[ind]];
            
            cur[target] = (nottake +take);
        }
        prev=cur;
    }
    
    return prev[tar];
}

int main(){
    vector<int> num ={1,2,2,3};
    int tar = 3;
    cout<<findWays(num,tar)<<endl;
}