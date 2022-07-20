#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int t_sum =0;
    for(auto i:arr) t_sum+=i;
    vector<vector<bool>> dp(n,vector<bool> (t_sum+1,false));
    
    for(int i=0;i<n;i++) dp[i][0]=true;
    if(arr[0]<=t_sum) dp[0][arr[0]]=true;
    
    for(int ind=1;ind<n;ind++){
        for(int target =1;target<=t_sum;target++){
            bool nottake = dp[ind-1][target];
            bool take =false;
            if(arr[ind]<=target)
                take = dp[ind-1][target-arr[ind]];
            
            dp[ind][target]= take|nottake;
        }
    }


    //glanc at dp
    for(auto it:dp){
        for(auto it1:it){
            cout << it1 << " ";
        }
        cout << endl;
    }
    
    int mini=1e8;
    for(int i=0;i<=t_sum;i++){
        if(dp[n-1][i])
        mini = min(mini,abs(2*i-t_sum)); 
    }
    
    return mini;
}


int main(){
   
   vector<int> arr = {3,2,7};
   cout<<minSubsetSumDifference(arr,arr.size())<<endl;
}