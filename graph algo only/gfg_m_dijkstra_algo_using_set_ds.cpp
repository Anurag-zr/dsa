#include<bits/stdc++.h>
using namespace std;


vector<int> dijkstra(int V,vector<vector<int>> adjList[],int S){

    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);
    dist[S] = 0;

    st.insert({0, S});

    while(!st.empty()){
        int node = (*st.begin()).second;
        st.erase(*st.begin());

        for(auto it:adjList[node]){
            int edgeWt = it[1];
            int adjNode = it[0];

            if(dist[node]+edgeWt<dist[adjNode]){

                if(dist[adjNode]!=1e9)
                    st.erase({dist[adjNode], adjNode});

                dist[adjNode]=dist[node] + edgeWt;
                st.insert({dist[adjNode],adjNode});
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