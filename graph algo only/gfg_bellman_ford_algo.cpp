#include<bits/stdc++.h>
using namespace std;

    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        
        vector<int> dist(V,1e8);
        dist[S]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto it:edges){
                int u= it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u]+wt<dist[v]){
                    dist[v]= dist[u]+wt;
                }
            }
        }
        
        
        //nth relaxation to check if
        //graph contian -ve path cycle
            for(auto it:edges){
                int u= it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u]+wt<dist[v]){
                    return {-1};
                }
            }
            
            return dist;
    }


int main(){
    /*
    
    E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]
S = 2
Output:
1 6 0
    
    */

    vector<vector<int>> edges = {
        {0, 1, 5}, {1, 0, 3}, {1, 2, -1}, {2, 0, 1}};

    int S = 2;
    int V = 3;

    vector<int> dist = bellman_ford(V, edges, S);

    for(auto i: dist)
                cout << i << " ";
}