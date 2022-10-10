#include<bits/stdc++.h>
using namespace std;

  void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<int>> &grid,vector<pair<int,int>> &ds,int r0,int c0){
      if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || vis[r][c] || grid[r][c]==0 ) return;
      
      vis[r][c]=1;
      ds.push_back({r-r0,c-c0});
      
      dfs(r-1,c,vis,grid,ds,r0,c0);
      dfs(r,c+1,vis,grid,ds,r0,c0);
      dfs(r+1,c,vis,grid,ds,r0,c0);
      dfs(r,c-1,vis,grid,ds,r0,c0);
  }

 
//  void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<int>> &grid,vector<pair<int,int>> &ds,int r0,int c0){
     
//      vis[r][c]=1;
//      ds.push_back({r-r0,c-c0});
     
//      vector<int> dr = {-1,0,+1,0};
//      vector<int> dc = {0,+1,0,-1};
     
//      for(int i=0;i<4;i++){
//          int nr = r+ dr[i];
//          int nc = c + dc[i];
         
//          if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]==1){
//              dfs(nr,nc,vis,grid,ds,r0,c0);
//          }
//      }
     
//  }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vector<pair<int,int>> ds;
                    dfs(i,j,vis,grid,ds,i,j);
                     st.insert(ds);
                }
            }
        }
        
        // for(auto it:st){
        //     for(auto it1:it){
        //         cout<<it1.first<<"-"<<it1.second<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        return st.size();
    }


int main(){
  vector<vector<int>> grid= {
                {1, 1, 0, 1, 1},
                {1, 0, 0, 0, 0},
                {0, 0, 0, 1, 1},
                {1, 1, 0, 1, 0}};

  cout << countDistinctIslands(grid) << endl;
}