#include<bits/stdc++.h>
using namespace std;


    int minDistance(string word1, string word2) {
        int n= word1.length();
        int m = word2.length();
        
        //tabulation method to calculate longest common substring
        //1 based indexing
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                    dp[i][j] = 0+ max(dp[i][j-1],dp[i-1][j]);
            }
        }
        
      int lcs = dp[n][m];
        
        
        return n+m - 2*lcs;
        
    }


    int main(){
        string str1 = "leetcode";
        string str2 = "etco";

        cout << minDistance(str1, str2) << endl;
    }