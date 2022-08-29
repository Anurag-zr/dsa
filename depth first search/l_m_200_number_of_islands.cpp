#include<bits/stdc++.h>
using namespace std;

    void dfsMarking(vector<vector<char>> &grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0') return;
        
         grid[i][j]='0';
        dfsMarking(grid,i+1,j);
        dfsMarking(grid,i,j-1);
        dfsMarking(grid,i-1,j);
        dfsMarking(grid,i,j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        
        int count_island=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfsMarking(grid,i,j);
                    count_island++;
                }
            }
        }
        
        return count_island;
    }

int main(){
/*
    // Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
*/

vector<vector<char>> grid = {
    {'1', '1', '0', '0', '0'},
    {'1', '1', '0', '0', '0'},
    {'0', '0', '1', '0', '0'},
    {'0', '0', '0', '1', '1'},
};

cout << numIslands(grid) << endl;
}