#include<bits/stdc++.h>
using namespace std;


void create(int n,int m,vector<int> adj[]){
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

   void dfs(int node,vector<int> &vis,vector<int> &dfsList,vector<int> adj[]){
        vis[node]=1;
        dfsList.push_back(node);
        
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,dfsList,adj);
            }
        }
    
    }

vector<int> dfsOfGraph(int V,vector<int> adj[]){ 

        vector<int> vis(V);
        vector<int> dfsList;
        dfs(0,vis,dfsList,adj);
        
        return dfsList;
}


int main(){
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];

    create(n, m, adj);

    vector<int> dfsList = dfsOfGraph(n, adj);

    for(auto it:dfsList){
        cout << it << " ";
    }
}