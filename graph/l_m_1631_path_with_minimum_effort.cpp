#include<bits/stdc++.h>
using namespace std;

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        dist[0][0] = 0;
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            
            if(r == n-1 & c==m-1) return pq.top().first;
            
            pq.pop();
            
            for(int i=0;i<4;i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                
                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                
                int newEffort = max(abs(heights[r][c] - heights[nr][nc]),dist[r][c]);
                
                if(newEffort< dist[nr][nc]){
                    dist[nr][nc] = newEffort;
                    pq.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        
        
        return 0;
    }

int main(){

    /*
    Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
    */

        vector<vector<int>> heights = {
            {1, 2, 2},
            {3, 8, 2},
            {5, 3, 5}};

        cout << minimumEffortPath(heights) << endl;
}