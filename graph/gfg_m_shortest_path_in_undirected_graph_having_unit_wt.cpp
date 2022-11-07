#include<bits/stdc++.h>
using namespace std;


    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adjList[N];
        
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int> dist(N,-1);
        
        int vis[N]={0};
        queue<pair<int,int>> q;
        q.push({src,0});
        dist[src]=0;
        vis[src]=1;
        
        while(!q.empty()){
            auto pair = q.front();
            q.pop();
            int node = pair.first;
            int minDis = pair.second;
            // cout<<node<<" "<<minDis<<endl;
            dist[node] = minDis;
            
            for(auto adjNode: adjList[node]){
                if(!vis[adjNode]) {
                    q.push({adjNode,minDis+1});
                    vis[adjNode]=1;
                }
            }
        
        }

        return dist;
    }


int main(){
    /*
    Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4 ,5]
,[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4
    */

    int n = 9;
    int m = 10;
    int src = 0;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {3, 4},
        {4, 5},
        {5, 6},
        {1, 2},
        {2, 6},
        {6, 7},
        {7, 8},
        {6, 8}};

    vector<int> ans = shortestPath(edges, n, m, src);

    int node = 0;
    for(auto i:ans){
        cout << node<< "->" << i << endl;
        node++;
    }
}