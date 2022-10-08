#include<bits/stdc++.h>
using namespace std;

    
    void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<int>> &grid){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || vis[r][c] || grid[r][c]==0) return;
        
        vis[r][c]=1;
        
        dfs(r-1,c,vis,grid);
        dfs(r,c+1,vis,grid);
        dfs(r+1,c,vis,grid);
        dfs(r,c-1,vis,grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        //trverse first and last row
        for(int j=0;j<m;j++){
            //first row
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(0,j,vis,grid);
            }
            
            //last row
            if(grid[n-1][j]==1 && !vis[n-1][j]) dfs(n-1,j,vis,grid);
        }
        
        //traverse first and last col
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]) dfs(i,0,vis,grid);
            if(grid[i][m-1]==1 && !vis[i][m-1]) dfs(i,m-1,vis,grid);
        }
        
        
        int count =0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]) count++;
            }
        }
        
        
        return count;
    }


int main(){
    // Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3

    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    cout << numEnclaves(grid) << endl;
}