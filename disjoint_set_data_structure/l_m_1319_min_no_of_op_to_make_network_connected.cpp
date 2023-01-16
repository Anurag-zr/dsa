#include<bits/stdc++.h>
using namespace std;

class  DisjointSet{
    public: 
      vector<int> parent;
      vector<int> size;
      
    public:
       
       DisjointSet(int n){
           parent.resize(n+1);
           size.resize(n+1,1);
           
           for(int i=0;i<=n;i++) parent[i]=i;
       }
       
       
       int findUParent(int u){
           if(parent[u]==u) return u;
           
           return parent[u] = findUParent(parent[u]);
       }
       
       void unionBySize(int u,int v){
           int upu = findUParent(u);
           int upv = findUParent(v);
           
           if(upu==upv) return;
           
           if(size[upu]< size[upv]){
               parent[upu]= upv;
               size[upv]+=size[upu];
           }
           
           if(size[upv]<=size[upu]){
               parent[upv]=upu;
               size[upu]+=size[upv];
           }
       }
};

    int makeConnected(int n, vector<vector<int>>& connections) {
        int numCable = connections.size();
        
        if(numCable+1<n) return -1;
        
        DisjointSet ds(n);
        
        int numComponent =n;
        for(auto it: connections){
            int u=it[0];
            int v = it[1];
            
            if(ds.findUParent(u)==ds.findUParent(v)) continue;
            
            ds.unionBySize(u,v);
            numComponent--;
        }
        
        return numComponent-1;
    }

int main(){
    /*
    
    Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
    */

    int n = 6;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    cout << makeConnected(n, edge) << endl;
}