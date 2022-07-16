#include <bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>> &grid) {
 //space optimized 
    int m = grid.size();
    int n= grid[0].size();
    
    vector<int> prev(n,1e9);
    vector<int> cur(n,0);
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                cur[j]= grid[i][j];
                continue;
            }
            
            int left = 1e9;
            
            int up = grid[i][j] + prev[j];
            if(j>0) left = grid[i][j] + cur[j-1];
            
            
            cur[j] = min(up,left);
        }
        
        prev=cur;
    }
    
    return prev[n-1];
}


//tabulation solution
// // int minSumPath(vector<vector<int>> &grid) {
//     // Write your code here.
//     //tabulation soln
    
//     int m = grid.size();
//     int n= grid[0].size();
    
//     vector<vector<int>> dp(m,vector<int> (n,0));
    
//     dp[0][0]= grid[0][0];
    
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(i==0 && j==0) continue;
//             int up = 1e9;
//             int left = 1e9;
//             if(i>0) 
//                 up = grid[i][j] + dp[i-1][j];
//             if(j>0)
//                 left = grid[i][j] + dp[i][j-1];
            
//             dp[i][j] = min(up,left);
//         }
//     }
    
//     return dp[m-1][n-1];
// }


int main(){
    vector<vector<int>> grid = {{2, 3, 3, 2}, {1, 2, 2, 1}, {4, 3, 2, 1}};
    cout << minSumPath(grid) << endl;
}