#include<bits/stdc++.h>
using namespace std;

    //memoization
    bool f(int i,int j,string &p,string &s,vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0){
            for(int k =0;k<=i;k++){
                if(p[k]!='*') return false;
            }
            
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(p[i]==s[j] || p[i] =='?')  return dp[i][j] = f(i-1,j-1,p,s,dp);
        if(p[i]=='*') {
            return dp[i][j] = f(i-1,j,p,s,dp) | f(i,j-1,p,s,dp);
        }
        
        return false;
    }

    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        
        return f(n-1,m-1,p,s,dp);
    }
    
    int main(){
        string s = "abdefcd";
        string p = "ab*cd";
        cout << isMatch(s, p) << endl;
    }


