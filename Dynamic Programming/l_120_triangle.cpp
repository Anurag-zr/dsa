#include<bits/stdc++.h>
using namespace std;

//memoization soln
    int f(int i,int j,vector<vector<int>> &triangle,vector<vector<int>> &dp){
        
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down = triangle[i][j] + f(i+1,j,triangle,dp);
        int dia = triangle[i][j] + f(i+1,j+1,triangle,dp);
        
        return dp[i][j] =min(down,dia);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m= triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(0,0,triangle,dp);
    }


    //tabulation solution|space optimized
    int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<int> prev(n,0);
    
    for(int i=0;i<n;i++){
        prev[i] = triangle[n-1][i];
    }
    
    vector<int> cur(n,0);
    
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            
            int up = triangle[i][j] + prev[j];
            int dia = triangle[i][j] + prev[j+1];
            cur[j] = min(up,dia);
        }
        
        prev = cur;
    }
    
    return prev[0];
}


    int main(){
        //memoization
        vector<vector<int>> grid = {{1}, {2, 3}, {4, 6, 1}};
        // cout << minimumTotal(grid) << endl;

        //tabulation solution
        cout<<minimumPathSum(grid,grid.size())<<endl;
    }