#include<bits/stdc++.h>
using namespace std;

    
    static bool compare(pair<int,char> a,pair<int,char> b){
        if(a.first==b.first){
            return a.second < b.second;
        }
        
        return a.first<b.first; //max value at top
    }
    
    string frequencySort(string s) {
        unordered_map<char,int> umap;
        
        for(auto c:s){
            umap[c]++;
        }
    
        priority_queue<pair<int,char>,vector<pair<int,char>>,decltype(&compare)> pq(compare);
        
        for(auto it:umap) pq.push({it.second,it.first});
        
        string ans="";
        
        while(!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();
            
            while(p.first--){
                ans+=p.second;
            }
        }
        
        return ans;
    }

int main(){
    string s = "aabcddcaacvbgioodcppq";
    cout<<frequencySort(s) << endl;
}