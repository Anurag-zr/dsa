#include<bits/stdc++.h>
using namespace std;

    bool dfs(int node,int &dest,vector<int> adjList[],vector<int> &vis){
        if(node == dest) return true;
        
         for(auto adjNode: adjList[node]){
             if(!vis[adjNode]){
                 vis[adjNode]=1;
             if(dfs(adjNode,dest,adjList,vis)==true) return true;
             }
         }
        
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adjList[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> vis(n,0);
        vis[source]=1;
     return  dfs(source,destination,adjList,vis);
    }


int main(){
 /********************************
Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
*/

     int n = 6;
     int src = 0;
     int dest = 5;
     vector<vector<int>> edges = {
         {0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};

    cout<<validPath(n,edges,src,dest)<<endl;
}