#include<bits/stdc++.h>
using namespace std;


    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        vector<int> dist(V,1e9);
        dist[S]=0;
        
        min_heap.push({0,S});
      
        while(!min_heap.empty()){
            int node = min_heap.top().second;
            min_heap.pop();
                  
            for(auto it : adj[node]){
                int adjNode = it[0];
                int adjNodeWt = it[1];
                //relaxing the edges of node
                if(dist[node]+adjNodeWt<dist[adjNode]){
                    dist[adjNode]=dist[node]+ adjNodeWt;
                    min_heap.push({dist[adjNode],adjNode});
                }
            }
        }
        
        
        return dist;
    }

int main(){
    vector<vector<int>> adjList[] = {
        {{1, 4}, {2, 4}},
        {{0, 4}, {2, 2}},
        {{0, 4}, {1, 2}, {3, 3}, {4, 1}, {5, 6}},
        {{2, 3}, {5, 2}},
        {{2, 1}, {5, 3}},
        {{3, 2}, {4, 3}, {2, 6}}};

    int V = 6; //number of nodes
    int S = 0; // src node

    vector<int> minDist = dijkstra(V, adjList, S);

    for (int i = 0; i < V;i++){
            cout << i << "->" << minDist[i] << endl;
    }
}