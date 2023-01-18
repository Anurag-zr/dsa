#include<bits/stdc++.h>
using namespace std;

	//Function to find number of strongly connected components in the graph.
	
	void dfs(int node,int vis[],stack<int> &stk,vector<int> adj[]){
	    vis[node]=1;
	    
	    for(auto adjNode : adj[node]){
	        if(vis[adjNode]) continue;
	        
	        dfs(adjNode,vis,stk,adj);
	    }
	    
	    stk.push(node);
	}
	
	
	void dfs2(int node,vector<int> &scc,int vis[],vector<int> revAdj[]){
	    vis[node]=1;
	    scc.push_back(node);
	    
	    for(auto adjNode: revAdj[node]){
	        if(vis[adjNode]) continue;
	        
	        dfs2(adjNode,scc,vis,revAdj);
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        int vis[V]={0};
        stack<int> stk;
        
        //sort nodes acc to finishing time
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,stk,adj);
            }
        }
        
        //step 2 : reverse graph
        vector<int> revAdj[V];
        for(int i=0;i<V;i++){
            for(auto adjNode: adj[i]){
                revAdj[adjNode].push_back(i);
            }
        }
        
        memset(vis,0,sizeof(vis));
        int ans=0;
        vector<vector<int>> allSCC;
        while(!stk.empty()){
            int node = stk.top();
            stk.pop();
            
            if(vis[node]) continue;
             
             ans++;
             vector<int> scc;
             
             dfs2(node,scc,vis,revAdj);
             allSCC.push_back(scc);
        }
        
        for(auto scc: allSCC){
            for(auto i: scc){
                cout<<i<<" "; 
            }
            cout<<endl;
        }
        
        
        return ans;
    }

int main(){
    int v = 5;
    vector<int> adj[] = {
        {2, 3}, {0}, {1}, {4}, {}};

    int ans = kosaraju(v, adj);
    cout << "no. of scc = " << ans << endl;
}