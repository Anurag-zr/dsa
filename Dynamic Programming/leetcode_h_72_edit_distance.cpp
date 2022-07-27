#include<bits/stdc++.h>
using namespace std;


    
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


    int main(){
        string word1 = "horse";
        string word2 = "ros";

        cout << minDistance(word1, word2) << endl;
    }