#include<bits/stdc++.h>
using namespace std;


    int findPath(int i,int j,vector<vector<int>> &grid,bool dir){
        // cout<<i<<" "<<j<<" "<<dir<<endl;
        if(j<0 || j>=grid[0].size()) return -1;
        
        if(i>=grid.size()) return j;
        
        if(j+1>=0 && j+1<grid[0].size() && grid[i][j]==1  && grid[i][j+1]== -1 && dir) return -1;
        
        if(j-1>=0 && j-1<grid[0].size() && grid[i][j]==-1 && grid[i][j-1] == 1  && dir) return -1;
        
        
        
        int ans;
        if(dir){  // left or right
            // cout<<i<<" "<<j<<" "<<dir<<endl;
          if(grid[i][j]==1) ans = findPath(i,j+1,grid,false);
          else  ans = findPath(i,j-1,grid,false);
        }
        else{
            // cout<<i<<" "<<j<<" "<<dir<<endl;
            ans = findPath(i+1,j,grid,true);
        }
        
        
        return ans;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        
        int m = grid.size();
        int n = grid[0].size();
        
        bool dir =true; // true mean left or right, false mean down
        for(int i=0;i<n;i++){
            dir =true;
            ans.push_back(findPath(0,i,grid,dir));
            // cout<<endl;
        }
        
        
        return ans;
    }


int main(){
    // Input: grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1},
        {-1, -1, -1, -1, -1, -1},
        {1, 1, 1, 1, 1, 1},
        {-1, -1, -1, -1, -1, -1}};

    vector<int> ans = findBall(grid);
    for(auto i:ans){
        cout << i << " ";
    }
}