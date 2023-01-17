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

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        vector<int> dx ={-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                
                for(int k=0;k<4;k++){
                    int ni = i+ dx[k];
                    int nj = j+ dy[k];
                    
                    if(ni<0 || ni>=n || nj<0 || nj>=n || grid[ni][nj]==0) continue;
                    
                    int nodeNo = i*n +j;
                    int adjNodeNo = ni*n +nj;
                    
                    ds.unionBySize(nodeNo,adjNodeNo);
                }
            }
        }
        
        
        //step2
        
        int maxi = -1e9;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                
                set<int> component;
                for(int k=0;k<4;k++){
                    int ni = i+ dx[k];
                    int nj = j+ dy[k];
                   
                    if(ni<0 || ni>=n || nj<0 || nj>=n || grid[ni][nj]==0) continue;
                    
                    component.insert(ds.findUParent(ni*n+nj));
                }
                
                int totalSize=0;
                for(auto it: component){
                    totalSize+=ds.size[it];
                }
                
                maxi = max(maxi,totalSize+1);
            }
        }
        
        
        return maxi==-1e9 ? n*n : maxi;
    }


    int main(){
        vector<vector<int>> grid = {
            {1, 0}, {0, 1}};

        cout<<largestIsland(grid)<<endl;
    }