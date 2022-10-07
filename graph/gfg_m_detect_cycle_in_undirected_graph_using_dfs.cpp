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

  bool dfs(int src,int parent,vector<int> &vis,vector<int> adj[]){
      vis[src]=1;
      for(auto adjNode:adj[src]){
          if(!vis[adjNode]){
            if(dfs(adjNode,src,vis,adj)==true) return true;
          }
          else if(parent!=adjNode){
            // parent != adjNode : then there is a cycle
            return true;
          }
      }
      
      return false;
  }

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)==true) return true;
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

    cout << isCycle(n, adjList)<<endl;
}