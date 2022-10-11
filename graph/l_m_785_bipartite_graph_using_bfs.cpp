#include<bits/stdc++.h>
using namespace std;

    bool bfs(int start,vector<int> &vis,vector<vector<int>> &graph){
        vis[start]=0; //color 0
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto adjNode: graph[node]){
                if(vis[adjNode]==-1) {//not visited
                    vis[adjNode]= !vis[node];
                    q.push(adjNode);
                }
                else if(vis[adjNode] == vis[node]){ //already visited and of same color as parent,then graph is not bipartite
                    return false;
                }
                else{ // visited but of different color as parent then it's okay
                    
                }
            }
        }
        
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> vis(n,-1); //intially no color to any node
        
        for(int i =0;i<n;i++){
            if(vis[i]==-1) 
                if(bfs(i,vis,graph)==false) return false;
        }
        
        return true;
    }

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

    int main(){
        // cin no. of nodes and edges
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adjList = create(n, m);

        cout << isBipartite(adjList) << endl;
    }

