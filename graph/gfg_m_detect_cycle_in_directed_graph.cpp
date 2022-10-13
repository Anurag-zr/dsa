#include<bits/stdc++.h>
using namespace std;

  bool dfs(int node,vector<int> &vis,vector<int> &pathVis,vector<int> adj[]){
      vis[node]= 1;
      pathVis[node]=1;
      
      for(auto adjNode: adj[node]){
          if(!vis[adjNode]){
              if(dfs(adjNode,vis,pathVis,adj)==true) return true;
          }
          else if(vis[adjNode] && pathVis[adjNode]){
              return true;
          }
      }
      
      pathVis[node]=0;
      return false;
      
  }
  
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0); // initailly not visited
        vector<int> pathVis(V,0); // mark that node only that form the current path
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)==true) return true;
            }
        }
        
        return false;
    }

    void createGraph(int n, int m, vector<int> adjList[]){
        for (int i = 0; i < m;i++){
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
        }
    }

    int main(){
        int n, m;
        cin >> n >> m;

        vector<int> adjList[n];
        createGraph(n, m, adjList);

        cout << isCyclic(n, adjList) << endl;
    }