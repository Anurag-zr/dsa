#include<bits/stdc++.h>
using namespace std;


void create(int n,int m,vector<int> adj[]){
    for (int i = 0; i < m;i++){
        int u, v;
        cin>>u >> v;
        adj[u].push_back(v);
    }
}

	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++){
	        for(auto adjNode:adj[i]){
	            indegree[adjNode]++;
	        }
	    }
	    
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> topo;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto adjNode:adj[node]){
	            indegree[adjNode]--;
	            if(indegree[adjNode]==0) q.push(adjNode);
	        }
	    }
	    
	    
	    return topo;
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