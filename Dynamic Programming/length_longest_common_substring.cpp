#include<bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2){
	//	Write your code here.
    int n = str1.length();
    int m = str2.length();
    
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    int maxi = dp[0][0];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(str1[i-1]== str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi,dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    return maxi;
}

int lcsSO(string &str1,string &str2){
   int n = str1.length();
   int m = str2.length();

   vector<int> prev(m + 1, 0);
   vector<int> cur(m + 1, 0);
   int maxi = prev[0];

   for (int i = 1; i <= n;i++){
       for (int j = 1; j <= m;j++){

        if(str1[i-1]==str2[j-1]){
            cur[j] = 1+prev[j - 1];
            maxi = max(maxi, cur[j]);
        }
        else{
            cur[j] = 0;
        }

       }

       prev = cur;
   }

   return maxi;
}

int main(){
    string str1 = "abcd";
    string str2 = "abzd";

    //longest common substring tabulation
    cout << lcs(str1, str2) << endl;

    //longest common substring space optimizaion
    cout << lcsSO(str1, str2) << endl;
}