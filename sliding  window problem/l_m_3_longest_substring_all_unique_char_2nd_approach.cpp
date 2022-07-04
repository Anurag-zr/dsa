#include <bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstring(string s){
    int maxlength = 0;
    int uniquechar = 0;
    unordered_map<char, int> umap;

    int i = 0;
    for (int j = 0; j < s.size();j++){
        if(umap.find(s[j]) == umap.end()){
            umap[s[j]]++;
            uniquechar++;
        }
        else{
            umap[s[j]]++;
        }

        if(uniquechar == j-i+1){
            maxlength = max(maxlength, j - i + 1);
        }
        else if(uniquechar < j-i+1){
            while(uniquechar < j-i+1){
                umap[s[i]]--;
                if(umap[s[i]]==0){
                    uniquechar--;
                    umap.erase(s[i]);
                }
                i++;
            }

            if(uniquechar == j-i+1){
                maxlength = max(maxlength, j - i + 1);
            }
        }
    }

    return maxlength;
}


int main(){
    // string s = "pwwkew";
    // string s = "dvdf";
    string s = "aaaabcdefazobbeec";
    cout << lengthOfLongestSubstring(s) << endl;
}