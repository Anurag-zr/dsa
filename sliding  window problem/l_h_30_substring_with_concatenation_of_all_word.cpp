#include<bits/stdc++.h>
using namespace std;


    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        
        unordered_map<string,int> count;
        for(auto s: words){
            count[s]++;            
        }
        
        unordered_map<string,int> seen;
        int n = s.length();
        int num = words.size();
        int len = words[0].size();
        
        int i=0;
        for(int j=0;j<n;j++){
            
            if(j-i+1==num*len){
                unordered_map<string,int> seen;
                int k =0;
                
                while(k<num){
                    string word = s.substr(i+k*len,len);
                    if(count.find(word)!=count.end()){
                      seen[word]++;
                        if(seen[word]>count[word]) break;
                    }
                    else{
                        break;
                    }
                 k++;
                }
                
                if(k==num){
                    ans.push_back(i);
                }
                
                seen.clear();
                
                i++;
            }
            
        }
        
        
        return ans;
    }






int main(){
    //s = "barfoothefoobarman", words = ["foo","bar"]

    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};

    vector<int> ans = findSubstring(s, words);

    for (auto i: ans){
        cout << i << " ";
    }
}