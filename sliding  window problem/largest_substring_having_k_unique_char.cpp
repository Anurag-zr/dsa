#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {
    // your code here
    int i=0;
    int maxlen = -1;
    int uniquechar =0;
    unordered_map<char,int> umap;
    
    for(int j=0;j<s.length();j++){
        cout << uniquechar << endl;
        if(umap.find(s[j])==umap.end()){
            uniquechar++;
            umap[s[j]]++;
        }else{
            
            umap[s[j]]++;
        }
        
        
        if(uniquechar == k){
            maxlen = max(maxlen, j-i+1);
        }
        
        else if(uniquechar>k){
            while(uniquechar > k){
                umap[s[i]]--;
                if(umap[s[i]] == 0){
                    uniquechar--;
                    umap.erase(s[i]);
                }
                i++;
            }

            if(uniquechar == k){
                maxlen= max(maxlen,j-i+1);
            }
        }
        
        
        
    }

    return maxlen;
}


int main(){

    // string s = "aabacbebebe";
    string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    int k = 5;

    cout << longestKSubstr(s, k);
}