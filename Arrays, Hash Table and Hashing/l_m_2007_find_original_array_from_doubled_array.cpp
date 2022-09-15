#include<bits/stdc++.h>
using namespace std;


    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int> umap;
        vector<int> original;
        
        sort(changed.begin(),changed.end());
        
        for(int i=0;i<changed.size();i++){
            // it means we have previously encountered its half
            if(umap.find(changed[i])!=umap.end()){ 
                original.push_back(changed[i]/2);
                umap[changed[i]]--;
                if(umap[changed[i]]==0) umap.erase(changed[i]);
            }
            else{
                umap[changed[i]*2]++;
            }
        }
        
        if(umap.size()==0) return original;
        else return {};
    }


int main(){
    vector<int> doubled = {1, 4, 2, 4, 2, 8};
    vector<int> ans = findOriginalArray(doubled);

    for(auto i:ans){
        cout << i << " ";
    }

}
