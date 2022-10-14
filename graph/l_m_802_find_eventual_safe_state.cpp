#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> create(int n,int m){
    vector<vector<int>> adjList(n , vector<int>());
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        // directed graph
        adjList[u].push_back(v);
    }

    return adjList;
}

    bool dfs(int node,vector<int> &vis,vector<int> &pathVis,vector<int> &markSafeNode,vector<vector<int>> &graph){
        
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto adjNode: graph[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode,vis,pathVis,markSafeNode,graph) == true) return true;
            }
            else if(vis[adjNode] && pathVis[adjNode]){
                return true;
            }
        }
        
        markSafeNode[node] =1;
        pathVis[node]=0;
        
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
       vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> markSafeNode(n,0);
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,markSafeNode,graph);
            }
        }
        
        for(int i=0;i<n;i++){
            if(markSafeNode[i]) ans.push_back(i);
        }
        
        
        return ans;
    }

int main(){
    cout << "create graph" << endl;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList = create(n, m);

    vector<int> safeNode = eventualSafeNodes(adjList);

    for(auto it:safeNode){
        cout << it << " ";
    }
    
}