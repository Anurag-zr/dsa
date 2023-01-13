#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> pipii;

// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
    vector<int> vis(V, 0);

    pq.push({0,{0, -1}});

    vector<pii> mst;
    int sum = 0;
    while (!pq.empty())
    {
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();

        if (vis[node])
            continue;

        vis[node] = 1;
        sum += cost;
        if(parent!=-1) mst.push_back({parent,node});

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int ew = it[1];

            if (!vis[adjNode])
            {
                pq.push({ew,{adjNode,node}});
            }
        }
    }

    for(auto i :mst){
        int parent = i.first;
        int node = i.second;
        cout << parent << " -> " << node << endl;
    }

    return sum;
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