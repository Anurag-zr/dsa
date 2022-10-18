#include<bits/stdc++.h>
using namespace std;

    //dfs function to find topo sort
    void dfs(int node,vector<int> &vis,stack<int> &st,vector<pair<int,int>> adjList[]){
        vis[node]=1;
        
        for(auto it:adjList[node]){
            int adjNode = it.first;
            if(!vis[adjNode]) dfs(adjNode,vis,st,adjList);
        }
        
        // cout<<node<<endl;
        st.push(node);
    }

    //topologiacal approach
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adjList[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adjList[u].push_back({v,wt});
        }
        
        stack<int> st;
        vector<int> vis(N,0);
        
        for(int i=0;i<N;i++){
            if(!vis[i]){ // find topo sort
                dfs(i,vis,st,adjList);
            }
        }
        
        vector<int> dist(N,1e9);
        int src =0;
        dist[src]=0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it:adjList[node]){
                int adjNode = it.first;
                int wt = it.second;
                
                if(dist[node]+wt<dist[adjNode]){
                    dist[adjNode] = dist[node]+wt;
                }
                
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9) // not reachable
             dist[i]=-1;
        }
        
        
        return dist;
        
    }


int main(){
//   5 5
// 0 1 2
// 2 1 2
// 2 4 2
// 1 4 8
// 1 3 6

int n ;
int m ;
cin >> n >> m;

vector<vector<int>> edges(m, vector<int>(3));
for(int i=0; i<m; i++){
    int u, v, wt;
    cin >> u >> v >> wt;
    edges[i][0] = u;
    edges[i][1] = v;
    edges[i][2] = wt;
}

vector<int> shortestDist = shortestPath(n,m,edges);

for (int i = 0; i < n;i++){
    cout << endl<< "0->" << i << " =" << shortestDist[i];
}
}