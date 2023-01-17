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

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cntCell = n*m;
        
        DisjointSet ds(cntCell);
        
        vector<int> dx ={-1,0,1,0};
        vector<int> dy ={0,1,0,-1};
        
        vector<int> ans;
        int cntIsland =0;
        
        for(auto it: operators){
            int i= it[0];
            int j = it[1];
            
            int cellNo = i*m + j;
            
            if(vis[i][j]) {
                ans.push_back(cntIsland);
                continue;
            }
            
            vis[i][j]=1;
            cntIsland++;
            
            for(int k=0;k<4;k++){
                int ni = i+dx[k];
                int nj = j+dy[k];
                
                if(ni<0 || ni>=n || nj<0 || nj>=m || !vis[ni][nj]) continue;
                
                int adjCellNo = ni*m +nj;
                
                if(ds.findUParent(cellNo) != ds.findUParent(adjCellNo)){
                    ds.unionBySize(cellNo,adjCellNo);
                    cntIsland--;
                }
                
            }
            
            
            ans.push_back(cntIsland);
            
        }
        
        
        return ans;
    }


    int main(){

        //size of island matrix
        int n = 4;
        int m = 5;

        vector<vector<int>> operators = {
            {0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};

        vector<int> ans = numOfIslands(n, m, operators);

        for(auto i: ans)
            cout << i << " ";
    }