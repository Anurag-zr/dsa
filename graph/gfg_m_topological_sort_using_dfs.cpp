#include<bits/stdc++.h>
using namespace std;


void create(int n,int m,vector<int> adj[]){
    for (int i = 0; i < m;i++){
        int u, v;
        cin>>u >> v;
        adj[u].push_back(v);
    }
}

    void dfs(int node,vector<int> &vis,stack<int> &st,vector<int> adj[]){
	    
	    vis[node]=1;
	    
	    for(auto adjNode:adj[node] ){
	        if(!vis[adjNode])
	        dfs(adjNode,vis,st,adj);
	    }
	    
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    stack<int> st;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,st,adj);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	       // cout<<st.top()<<" ";
	        st.pop();
	    }
	    
	    return ans;
	}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];
    create(n, m, adj);

    vector<int> toposort = topoSort(n,adj);

    for(auto it: toposort){
        cout << it << " ";
    }

}