#include<bits/stdc++.h>
using namespace std;

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adjList[n+1];
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        
        vector<int> dist(n+1,1e9),parent(n+1);
        dist[1] = 0;
        
        for(int i=0;i<n+1;i++) parent[i]=i;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,1});
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adjList[node]){
                int adjNode = it.first;
                int edgWt = it.second;
                
                if(dist[node]+edgWt< dist[adjNode]){
                    dist[adjNode]= dist[node]+edgWt;
                    parent[adjNode]=node;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        if(dist[n]==1e9) return {-1};
        
        vector<int> path;
        int node = n;
        while(parent[node]!=node){
            path.push_back(node);
            node =parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        
        return path;
        
    }


int main(){
    /*


    n = 5, m= 6
     edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
    
    */

    int n = 5;
    int m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}
    };

    vector<int> path = shortestPath(n, m, edges);

    for(auto i:path){
            cout << i << " ";
    }
}