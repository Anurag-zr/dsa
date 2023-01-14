#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    private:
    // vector<int> rank;  //for union by rank
    vector<int> parent;
    vector<int> size;  //for union by size

    public:
     DisjointSet(int n){
        // rank.resize(n+1,0);  //for 1 based indexing of graph
        parent.resize(n + 1);
        size.resize(n+1,1);    

        for (int i = 0; i < n + 1;i++){
            parent[i] = i;
            size[i] = 1;
        }
     }


     int findUParent(int u){
        if(parent[u]==u)
            return u;

        return parent[u] = findUParent(parent[u]);
     }

    //  void unionByRank(int u,int v){
    //     int upu = findUParent(u);
    //     int upv = findUParent(v);

    //     if(upu==upv)
    //         return;

    //     if(rank[upu]<rank[upv]){
    //         parent[upu] = upv;
    //     }
    //     else if(rank[upv]<rank[upu]){
    //         parent[upv] = upu;
    //     }
    //     else{ // rank[upu]==rank[upv]
    //         parent[upv] = upu;
    //         rank[upu]++;
    //     }
    //  }

    void unionBySize(int u,int v){
        int upu = findUParent(u);
        int upv = findUParent(v);

        if(upu==upv)
            return;

        if(size[upu]<size[upv]){
            parent[upu] = upv;
            size[upv] += size[upu];
        }
        else{
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};


int main(){

    /* 
    1,2
    2,3
    4,5
    6,7
    5,6
    3,7
    */

     DisjointSet ds(7);
     ds.unionBySize(1, 2);
     ds.unionBySize(2, 3);
     ds.unionBySize(4, 5);
     ds.unionBySize(6, 7);
     ds.unionBySize(5, 6);

     //1,5  belong to same component
     if(ds.findUParent(1) == ds.findUParent(5))
        cout << "yes" << endl;
        else
        cout << " no" << endl;

     ds.unionBySize(3, 7);

          //1,5  belong to same component
     if(ds.findUParent(1) == ds.findUParent(5))
        cout << "yes" << endl;
        else
        cout << " no" << endl;
}