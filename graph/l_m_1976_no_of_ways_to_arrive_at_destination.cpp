#include<bits/stdc++.h>
using namespace std;

int dijkstra(vector<long> &dist, vector<pair<int, int>> adjList[], int n)
{
    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
    pq.push({0, 0});

    int mod = 1e9 + 7;

    vector<int> ways(n, 0);
    ways[0] = 1;

    while (!pq.empty())
    {
        long node = pq.top().second;
        long dis = pq.top().first;
        pq.pop();

        for (auto it : adjList[node])
        {

            int adjNode = it.first;
            int ew = it.second;

            if (dis + ew == dist[adjNode])
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;

            if (dis + ew < dist[adjNode])
            {
                dist[adjNode] = dis + ew;
                pq.push({dist[adjNode], adjNode});

                // resetting the no of shortest ways of adjNode
                ways[adjNode] = ways[node] % mod;
            }
        }
    }

    for (auto i : ways)
        cout << i << " ";

    cout << endl;
    return (ways[n - 1] % mod);
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
     vector<pair<int,int>> adjList[n];
        for(auto it: roads){
            int u = it[0];
            int v = it[1];
            int t = it[2];
            
            adjList[u].push_back({v,t});
            adjList[v].push_back({u,t});
        }
        
        
        vector<long> dist(n,LONG_MAX);
        
        dist[0]=0;
        
       return  dijkstra(dist,adjList,n);
        
    }


int main(){

    /*
    Input: n = 7, roads = [[0,6,7],[0,1,2],
    [1,2,3],[1,3,3],[6,3,3],[3,5,1],
    [6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
    
    */

       int n = 7;
       vector<vector<int>> roads = {
           {0, 6, 7}, {0, 1, 2}, {1, 2, 3},
            {1, 3, 3}, {6, 3, 3}, {3, 5, 1},
             {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

       cout << countPaths(n, roads) << endl;
}
