 //leetcode hard 1192 critical connections in network
 // or finding bridges in graph

 #include<bits/stdc++.h>
 using namespace std;

 int timer = 1;

 void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges, vector<int> adj[])
 {
     vis[node] = 1;
     tin[node] = low[node] = timer;
     timer++;

     for (auto adjNode : adj[node])
     {
         if (adjNode == parent)
             continue;
         if (!vis[adjNode])
         {
             dfs(adjNode, node, vis, tin, low, bridges, adj);
             low[node] = min(low[node], low[adjNode]);

             // check node-- adjNode is critical node
             if (low[adjNode] > tin[node])
             {
                 bridges.push_back({node, adjNode});
             }
         }
         else
         {
             low[node] = min(low[node], low[adjNode]);
         }
     }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n,0);
        vector<int> tin(n);
        vector<int> low(n);
        
        vector<vector<int>> bridges;
        
        dfs(0,-1,vis,tin,low,bridges,adj);
        
        return bridges;
    }

 int main(){
    /*
    Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
    */

   int n =4;
   vector<vector<int>> connections = {
       {0, 1}, {1, 2}, {2, 0}, {1, 3}};

       vector<vector<int>> ans = criticalConnections(n,connections);
       

       for(auto it: ans){
        for(auto i: it){
             cout << i << " ";
        }
        cout << endl;
       }
 }