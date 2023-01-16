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

    int numProvinces(vector<vector<int>> adj) {
        // code here
        int n = adj.size();
        int m = adj[0].size();

        DisjointSet ds(n);
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1) ds.unionBySize(i,j);
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++) {
            if(ds.parent[i]==i)cnt++;
        }
        
        
        return cnt;
    }

int main(){
    /*
     
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2


     */

    vector<vector<int>> isConnected = {
        {1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    cout << numProvinces(isConnected) << endl;
}