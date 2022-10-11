#include <bits/stdc++.h>
using namespace std;

    bool dfs(int node,int colr,vector<int> &color,vector<int> adj[]){
        color[node] = colr;
        
        for(auto adjNode: adj[node]){
            if(color[adjNode]==-1){ // if not already visited
                if(dfs(adjNode,!colr,color,adj) == false) return false;
            }
            else if(color[adjNode] == color[node]){ // if already visited and same color as parent
            // then not bipartite graph
                
                return false;
            }
        }
        
        return true;
    }


	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1); // not colored
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            int colr =0;
	            if(dfs(i,colr,color,adj)==false)return false;
	        }
	    }
	    
	    return true;
	}

void create(int n,int m,vector<int> adj[]){
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    create(n, m, adj);

    cout<<isBipartite(n,adj)<<endl;

}