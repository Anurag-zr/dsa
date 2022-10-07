#include<bits/stdc++.h>
using namespace std;



void create(int n,int m,vector<int> adjList[]){
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        // directed graph
        adjList[u].push_back(v);
    }

}

    bool bfs(int src,vector<int> adj[],vector<int> &vis){
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent =q.front().second;
            q.pop();
            
            for(auto adjacentNode:adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode]=1;
                    q.push({adjacentNode,node});
                }
                else if(adjacentNode!=parent){
                    //already visited : then there is a cycle
                    return true;
                }
            }
        }
        
        return false;
    }


    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        
        for(int i =0;i<V;i++){
            if(!vis[i]){
                if(bfs(i,adj,vis)==true) return true;
            }
        }
        
        
        return false;
    }




int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> adjList[n + 1];

    create(n, m, adjList);

    cout << isCycle(n, adjList) << endl;
}