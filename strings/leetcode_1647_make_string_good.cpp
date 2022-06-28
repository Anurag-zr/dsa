#include <bits/stdc++.h>
using namespace std;

    int minDeletions(string s) {
      vector<int> freq(26);  
        for(char c: s){
            freq[c-'a']++;
        }
        
        sort(freq.begin(),freq.end());
        
        int prev;
        int diff =0;
        for(int i=24;i>=0;i--){
            if(freq[i]==0) break;
            
            if(freq[i]>=freq[i+1]){
                prev=freq[i];
                freq[i]=max(0,freq[i+1]-1);
                diff+= prev - freq[i];
            }
            
            
        }
        
        return diff;
    }

int main(){
    string s = "aabcaadcad";
    cout << minDeletions(s) << endl;
}