#include<bits/stdc++.h>
using namespace std;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        if(grid[0][0]!=0) return -1;
        
        dist[0][0]=1;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({1,{0,0}});
        
        while(!pq.empty()){
            int r = pq.top().second.first;
            int c= pq.top().second.second;
            pq.pop();
            
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    int nr = r + dr;
                    int nc = c + dc;
                    
                    if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
                    if(grid[nr][nc]==0 && dist[r][c]+1<dist[nr][nc]){
                        dist[nr][nc]=dist[r][c]+1;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
            
        }
        
        
        if(dist[n-1][n-1]==1e9) return -1;
        
        return dist[n-1][n-1];
        
    }


int main(){
/*
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
*/

        vector<vector<int>> grid = {
            {0, 0, 0},
            {1, 1, 0},
            {1, 1, 0}};

        cout << shortestPathBinaryMatrix(grid) << endl;
}