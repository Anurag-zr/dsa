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




    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        
        unordered_map<string,int> umap;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(umap.find(accounts[i][j])==umap.end()){ //if email don't exist in map
                    umap[accounts[i][j]]=i;
                }   
                else{
                    //exist already i.e this email must be a part of other user
                    int parent = umap[accounts[i][j]];
                    ds.unionBySize(parent,i);
                }
            }
        }
        
        vector<vector<string>> temp(n,vector<string>());
        
        for(auto it: umap){
            string key = it.first;
            int val = it.second;
            
            temp[ds.findUParent(val)].push_back(key);
        }
        
        vector<vector<string>> ans;
        
        for(int i=0;i<temp.size();i++){
            vector<string> details;
            if(temp[i].size()!=0) {
                details.push_back(accounts[i][0]);
                sort(temp[i].begin(),temp[i].end());
                details.insert(details.begin()+1,temp[i].begin(),temp[i].end());
            }
            
            if(details.size()) ans.push_back(details);
            
        }
        
        return ans;
    }

int main(){
    /*
    Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],
    ["John","johnsmith@mail.com","john00@mail.com"],
    ["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"]
,["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
    
    */

    vector<vector<string>> accounts = {
        {"John", "Johnsmith@mail.com", "John_newyork@mail.com"},
        {"John", "Johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnybravo@mail.com"}};

    vector<vector<string>> ans = accountsMerge(accounts);

    for(auto mails: ans){
        for(auto mail: mails){
                cout << mail << " ";
        }
        cout << endl;
    }


}