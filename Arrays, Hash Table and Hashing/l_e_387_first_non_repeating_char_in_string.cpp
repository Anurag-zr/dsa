#include<bits/stdc++.h>
using namespace std;


    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> umap;
        
        for(int i=0;i<s.length();i++){
            umap[s[i]].first++;
            umap[s[i]].second = i;
        }
        
        int ind = INT_MAX;
        
        for( auto& a:umap){
            if(a.second.first == 1){
                ind = min(ind,a.second.second);
            }
        }
        
        return ind==INT_MAX?-1:ind;
    }


    int main(){
        string s="leetcodl";
        int i = firstUniqChar(s);
        cout << s[i] << endl;
    }