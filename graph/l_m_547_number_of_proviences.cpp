#include <bits/stdc++.h>
using namespace std;


void create(int n,int m,vector<vector<int>> &adjMat){
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
}


    void dfs(int node,vector<int> &vis,vector<vector<int>> &isConnected){
        vis[node]=1;
         // add node element here to list for dfs traversal
        
        for(int i=0;i<isConnected[node].size();i++){
            if(isConnected[node][i]==1 &&  !vis[i]){
                dfs(i,vis,isConnected);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        
        int count_proviences =0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
            dfs(i,vis,isConnected);
            count_proviences++;
            }
        }
        
        return count_proviences;
    }



int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adjMat(n + 1, vector<int>(n + 1, 0));

    create(n, m, adjMat);

    cout << findCircleNum(adjMat);
}