#include<bits/stdc++.h>
using namespace std;


    int bfs(vector<vector<int>> &grid,vector<vector<int>> &vis,vector<int> &delRow,vector<int> &delCol,queue<pair<int,int>> &q){
        
        int cnt=0;

        while(!q.empty()){

            int size = q.size();
            
            bool flag =false;
            
            for(int j=0;j<size;j++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
              for(int i=0;i<delRow.size();i++){
                int nrow = row+delRow[i];
                int ncol = col +delCol[i];
                
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size()
                   && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                    flag=true;
                }
            }
                
        }
            
            if(flag) cnt++;
            
        }
        
        return cnt;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m= grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
       vector<int> delRow = {-1,0,+1,0};
       vector<int> delCol = {0,+1,0,-1};
        
        int maxi=0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==2 && !vis[i][j]){
                   vis[i][j]=1;
                    q.push({i,j});
                }
                
            }
        }
        
        maxi = bfs(grid,vis,delRow,delCol,q);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }
        
        
        return maxi;
    }


int main(){
    // [[2,1,1],[1,1,1],[0,1,2]]
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 1},
        {0, 1, 2}};

    cout << orangesRotting(grid) << endl;
}