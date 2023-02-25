#include<bits/stdc++.h>
using namespace std;


class DisjointSet{
    public: 
     
    vector<int> parent;
    vector<int> size;
    
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
        
        if(upu == upv) return;
        
        if(size[upu]>size[upv]){
            parent[upv]= upu;
            size[upu]+=size[upv];
        }
        else{
            parent[upu] = upv;
            size[upv]+=size[upu];
        }
    }
};




    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        
        DisjointSet ds(n);
        
        for(auto ele: allowedSwaps){
            int u = ele[0];
            int v= ele[1];
            
            ds.unionBySize(u,v);
        }
        
        
        unordered_map<int,vector<int>> umap;  // src-> {indexes}
        
        for(int i=0;i<n;i++){
            umap[source[i]].push_back(i);
        }
        
        int minDis=0;
        
        for(int i=0;i<n;i++){
            int targetEle = target[i];
            
            if(umap.find(targetEle)== umap.end()) minDis++;
            else{
                bool swapPos = false;
                for(int ind=0;ind<umap[targetEle].size();ind++){
                    if(ds.findUParent(i) == ds.findUParent(umap[targetEle][ind])){ //swap possible
                     
                        umap[targetEle].erase(umap[targetEle].begin()+ind);
                        swapPos = true;
                        break;
                    
                    }
                }
                
                if(swapPos == false) minDis++;
            }
        }
        
        return minDis;
    }



int main(){

    /* Initial
    
    Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
Output: 1
Explanation: source can be transformed the following way:
- Swap indices 0 and 1: source = [2,1,3,4]
- Swap indices 2 and 3: source = [2,1,4,3]
The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
    
    */

    vector<int> src = {1, 2, 3, 4};
    vector<int> tar = {2, 1, 4, 5};
    vector<vector<int>> allowedSwaps = {
        {0, 1}, {2, 3}};


    cout<<minimumHammingDistance(src,tar,allowedSwaps)<<endl;


}