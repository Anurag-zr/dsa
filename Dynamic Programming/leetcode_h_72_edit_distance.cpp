#include<bits/stdc++.h>
using namespace std;


//memoiztion solution    
    int f(int i,int j,string &str1,string &str2,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(str1[i]==str2[j]){
            return dp[i][j] = 0+ f(i-1,j-1,str1,str2,dp);
        }
        else{
            int insert = 1+ f(i,j-1,str1,str2,dp);
            int del = 1+f(i-1,j,str1,str2,dp);
            int replace = 1+f(i-1,j-1,str1,str2,dp);
            
            return dp[i][j] = min(insert,min(del,replace));
        }
    }
    
    int minDistance(string word1, string word2) {
      int n = word1.length();
      int m= word2.length();
       vector<vector<int>> dp(n,vector<int> (m,-1));
        
        return f(n-1,m-1,word1,word2,dp);
    }

    
//tabulation solution
    int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.length();
    int m = str2.length();
    
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    
    for(int i=0;i<=n;i++) dp[i][0] = i;
    for(int j=0;j<=m;j++) dp[0][j] = j;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = 0+ dp[i-1][j-1];
            }
            else{
                int insert = 1 + dp[i][j-1];
                int del = 1+ dp[i-1][j];
                int replace = 1+dp[i-1][j-1];
                
                dp[i][j] = min(insert,min(del,replace));
            }
        }
    }
    
    return dp[n][m];
}


    int main(){
        string word1 = "horse";
        string word2 = "ros";

        cout << minDistance(word1, word2) << endl;
        cout<< editDistance(word1, word2) << endl;
    }