#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class DisjointSet{
    private:
    vector<int> rank;  //for union by rank
    vector<int> parent;
    // vector<int> size;  //for union by size

    public:
     DisjointSet(int n){
        rank.resize(n+1,0);  //for 1 based indexing of graph
        parent.resize(n + 1);
        // size.resize(n+1,1);    

        for (int i = 0; i < n + 1;i++){
            parent[i] = i;
            // size[i] = 1;
        }
     }


     int findUParent(int u){
        if(parent[u]==u)
            return u;

        return parent[u] = findUParent(parent[u]);
     }

     void unionByRank(int u,int v){
        int upu = findUParent(u);
        int upv = findUParent(v);

        if(upu==upv)
            return;

        if(rank[upu]<rank[upv]){
            parent[upu] = upv;
        }
        else if(rank[upv]<rank[upu]){
            parent[upv] = upu;
        }
        else{ // rank[upu]==rank[upv]
            parent[upv] = upu;
            rank[upu]++;
        }
     }
};

	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pii>> edges;
        
        for(int i=0;i<V;i++)
        for(auto it: adj[i]){
            int v = it[0];
            int ew = it[1];
            
            edges.push_back({ew,{i,v}});
        }
        
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        
        int mstSum =0;
        vector<pair<pii, int>> mst;

        for(auto it :edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUParent(u)!=ds.findUParent(v)){
                mstSum+=wt;
                ds.unionByRank(u,v);
                mst.push_back({it.second, wt});
            }
            
        }

        for(auto it: mst){
            cout<<it.first.first<<" -> "<<it.first.second<<" "<<it.second<<endl;
        }
        
        return mstSum;
    }

int main(){
    /* 
    Input:
3 3
0 1 5
1 2 3
0 2 1

Output:
4
    
    */

    int V = 3;
    vector<vector<int>> adj[] = {
        {{1, 5}, {2, 1}},
        {{0,5},{2, 3}},
        {{0,1},{1,3}}};

    cout << spanningTree(V, adj) << endl;
}