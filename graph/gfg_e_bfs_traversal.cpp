#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> create(int n,int m){
    vector<vector<int>> adjList(n + 1, vector<int>());
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        // directed graph
        adjList[u].push_back(v);
    }

    return adjList;
}


    vector<int> bfsOfGraph(int V, vector<vector<int>> adj) {
        // Code here
        vector<int> bfs;
        vector<int> vis(V);
        
        queue<int> q;
        q.push(0);
        vis[0]=1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto i:adj[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        
        return bfs;
    }


int main(){
    // vector<int> adj[6];
    // adj[0] = {};
    // adj[1] = {};
    // adj[2] = {};
    // adj[3] = {};
    // adj[4] = {};
    // adj[5] = {};

    // int v = 5;

    int n; //no of nodes in the graph
    int m; //no of edges in Graph

    cin >> n >> m;

    vector<vector<int>> adjList(n + 1, vector<int>()); // for 1 based indexing
    adjList = create(n, m);

    vector<int> bfs;

    bfs = bfsOfGraph(n,adjList); 

    for(auto i:bfs){
        cout << i << " ";
    }
}