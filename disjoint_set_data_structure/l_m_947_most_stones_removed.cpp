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

    int removeStones(vector<vector<int>>& stones) {
        int n = 0;
        int m = 0;
        
        for(auto it: stones){
            n = max(n,it[0]);
            m = max(m,it[1]);
        }
        n++; // no. of rows
        m++; // no. of cols
        
        DisjointSet ds(n+m);
        unordered_map<int,int> stonesNode;
        
        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = n + it[1];
            
            ds.unionBySize(nodeRow,nodeCol);
            stonesNode[nodeRow]=1;
            stonesNode[nodeCol]=1;
        }
        
        int cnt =0;
        for(auto it: stonesNode){
            if(ds.findUParent(it.first)==it.first) cnt++;
        }
        
        
        return stones.size() - cnt;
    }


int main(){
    /* Initial
    
    Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
    */

    vector<vector<int>> stones = {
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};


cout<<removeStones(stones)<<endl;

}