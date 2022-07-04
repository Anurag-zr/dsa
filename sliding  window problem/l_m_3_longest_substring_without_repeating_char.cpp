#include<bits/stdc++.h>
using namespace std;

    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;
        vector<int> ans;
        int maxlength= 0;
        
        int i=0;
        for(int j=0;j<s.size();j++){
            if(umap.find(s[j])==umap.end()){
                umap[s[j]]+=1;
                maxlength++;
            }
            else{
                ans.push_back(maxlength);
                while(s[i]!=s[j]){
                    umap.erase(s[i]);
                    i++;
                    maxlength--;
                }

                i++;
                maxlength--;

                umap[s[j]] += 1;
                maxlength++;
            }

        }

        ans.push_back(maxlength);

        return *max_element(ans.begin(),ans.end());
    }

int main(){
    // string s = "pwwkew";
    // string s = "dvdf";
    string s = "aaaabcdefazobbeec";
    cout << lengthOfLongestSubstring(s) << endl;
}