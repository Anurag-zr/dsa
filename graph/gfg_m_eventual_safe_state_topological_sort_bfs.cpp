#include<bits/stdc++.h>
using namespace std;

// bfs: kahn's algorithm: topological sort
vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    // code here
    vector<int> revAdjList[V];

    for (int i = 0; i < V; i++)
    {
        for (auto adjNode : adj[i])
        {
            revAdjList[adjNode].push_back(i);
        }
    }

    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto adjNode : revAdjList[i])
        {
            indegree[adjNode]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto adjNode : revAdjList[node])
        {
            indegree[adjNode]--;
            if (indegree[adjNode] == 0)
                q.push(adjNode);
        }
    }

    sort(topo.begin(), topo.end());

    return topo;
    }

void create(int n,int m,vector<int> adjList[]){
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adjList[n];
    create(n,m,adjList);

    vector<int> safeNodes = eventualSafeNodes(n,adjList);

    for(auto it: safeNodes){
        cout << it << " ";
    }
}