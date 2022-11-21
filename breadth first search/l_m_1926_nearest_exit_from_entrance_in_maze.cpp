#include<bits/stdc++.h>
using namespace std;


    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n= maze.size();
        int m = maze[0].size();
        
        vector<int> dx ={-1,0,1,0};
        vector<int> dy  ={0,1,0,-1};
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{entrance[0],entrance[1]},0});
        maze[entrance[0]][entrance[1]]='+';
        
        while(!q.empty()){
            auto cell = q.front();
            int i= cell.first.first;
            int j = cell.first.second;
            int dist = cell.second;
            q.pop();
            // cout<<i<<" "<<j<<" "<<dist<<" "<<endl;
            if(!(i==entrance[0] && j==entrance[1]) && (i==0 || i==n-1 || j==0 || j==m-1))
                return dist;
            
            for(int it=0;it<4;it++){
                int nr = i+dx[it];
                int nc = j+dy[it];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && maze[nr][nc]=='.'){
                    maze[nr][nc]='+';
                    q.push({{nr,nc},dist+1});
                }
            }
            
        }
        
        
        
        return -1;
    }


int main(){

    // Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
// Output: 1

    vector<vector<char>> maze = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'}};

    vector<int>
        entrance = {1, 2};

    cout << nearestExit(maze, entrance) << endl;
}