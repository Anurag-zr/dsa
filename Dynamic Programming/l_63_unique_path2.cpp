#include <bits/stdc++.h>
using namespace std;

 int countPath(int i,int j,vector<vector<int>> &grid, vector<vector<int>> &dp){

     if(i==0 && j==0 && grid[i][j]==0){
          return 1;
      }
     
      if(i<0 || j<0){
          return 0;
      }
        
      
     if(grid[i][j]){
          return 0;
      } 
        
        
 
        
      if(dp[i][j]!=-1) return dp[i][j];
        
        int up = countPath(i-1,j,grid,dp);
        int left  = countPath(i,j-1,grid,dp);
        
        
        return dp[i][j]=up+left;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m= obstacleGrid.size();
      int n =obstacleGrid[0].size();
      vector<vector<int>> dp(m,vector<int> (n,-1));
      return countPath(m-1,n-1,obstacleGrid,dp);   
    }


int main(){
    // 1 : means obstacle , 0: means space
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << uniquePathsWithObstacles(grid) << endl;
}