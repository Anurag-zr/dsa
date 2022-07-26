#include<bits/stdc++.h>
using namespace std;

// memoization solution
int lcs(int i,int j,string &str,string &revstr,vector<vector<int>> &dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(str[i]==revstr[j]) 
        return dp[i][j]=1+ lcs(i-1,j-1,str,revstr,dp);
    return 
        dp[i][j] = 0+ max(lcs(i,j-1,str,revstr,dp),lcs(i-           1,j,str,revstr,dp));
}

int minInsertion(string &str)
{
    // Write your code here.
    string revstr = str;
    reverse(revstr.begin(),revstr.end());
    int n = str.length();
    
    vector<vector<int>> dp(n,vector<int> (n,-1));
    
    return n - lcs(n-1,n-1,str,revstr,dp);
}


//tabulation solution
    int tabu_minInsertions(string s) {
        string revs = s;
        reverse(revs.begin(),revs.end());
        int n = s.length();
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==revs[j-1])
                    dp[i][j]=1+ dp[i-1][j-1];
                else{
                    dp[i][j] = 0+ max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        
        
        return n-dp[n][n];
    }


    int main(){
        string s = "abcaa";
        cout<<minInsertion(s) << endl;

        cout << tabu_minInsertions(s) << endl;
    }