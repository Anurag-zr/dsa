#include<bits/stdc++.h>
using namespace std;

    void bfs(queue<pair<pair<int,int>,int>> &q,vector<vector<int>> &vis,vector<vector<int>> &dis,int n,int m){
        vector<int> dr = {-1,0,+1,0};
        vector<int> dc = {0,+1,0,-1};
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                int r = q.front().first.first;
                int c = q.front().first.second;
                int steps = q.front().second;
                q.pop();
                
                dis[r][c]=steps;
                
                for(int j=0;j<4;j++){
                    int nr = r +dr[j];
                    int nc = c +dc[j];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({{nr,nc},steps+1});
                    }
                }
                
            }
            
        }
        
        
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> vis(n,vector<int> (m,0));
	    vector<vector<int>> dis(n,vector<int> (m,0));
	    
	    queue<pair<pair<int,int>,int>> q;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==0){
	                vis[i][j]=1;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    
	    bfs(q,vis,dis,n,m);
	    
	    return dis;
    }


int main(){
//     Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]

// calc dist of nearest 0
vector<vector<int>> mat = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 1, 1}};

vector<vector<int>> ans = updateMatrix(mat);

for (auto it : ans)
{
    for (auto iit : it)
    {
        cout << iit << " ";
    }
    cout << endl;
    }
}