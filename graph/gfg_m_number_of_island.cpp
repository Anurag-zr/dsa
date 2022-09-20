#include<bits/stdc++.h>
using namespace std;


    void bfs(int row,int col,vector<vector<char>> &grid){
        grid[row][col]='0';
        queue<pair<int,int>> q;
        q.push({row,col});
        
        int n=grid.size();
        int m=grid[0].size();
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            for(int delrow =-1;delrow<=1;delrow++){
                for(int delcol = -1;delcol<=1;delcol++){
                    int nrow = i+delrow;
                    int ncol = j+delcol;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'){
                        grid[nrow][ncol]='0';
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }

    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n= grid.size();
        int m= grid[0].size();
        
        int cnt_island=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    bfs(i,j,grid);
                    cnt_island++;
                }
            }
        }
        
        return cnt_island;
    }



int main(){

// An island is surrounded by water and is formed by connecting
//  adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.


//T.C :- O(n^2)*8
//S.C :- O(n^2) for visited array + o(N^2) for queue

vector<vector<char>> grid = {
    {'1', '1', '0', '0', '1'},
    {'1', '1', '0', '0', '0'},
    {'0', '0', '1', '0', '0'},
    {'0', '0', '0', '1', '1'},
};

cout << numIslands(grid) << endl;
}