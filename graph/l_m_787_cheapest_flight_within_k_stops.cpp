#include<bits/stdc++.h>
using namespace std;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adjList[n];
        
        for(auto it:flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adjList[u].push_back({v,wt});
        }
        
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stops>k) continue;
            
            for(auto iter: adjList[node]){
                int adjNode = iter.first;
                int edgeWt = iter.second;
                
                if(cost+edgeWt < dist[adjNode] && stops<=k){
                    dist[adjNode] = cost+ edgeWt;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                    // cout<<adjNode<<" "<<node<<" "<<dist[adjNode]<<" "<<stops+1<<endl;
                }
            }
        }
        
        
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }


int main(){
    /*
    
    Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
    */

   int n =4;
   vector<vector<int>> flights = {
       {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};

   int src = 0;
   int dst = 3;
   int k = 1;

   cout << findCheapestPrice(n, flights, src, dst, k) << endl;
}