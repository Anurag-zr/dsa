#include<bits/stdc++.h>
using namespace std;


    int longestPalindrome(vector<string>& words) {
     
        int ans=0;
        int counter[26][26]={0};
        
        for(auto s:words){
            int a = s[0]-'a'; int b = s[1]-'a';
            
            if(counter[b][a]) {
                ans+=4;
                counter[b][a]--;
            }
            else{
                counter[a][b]++;
            }
        }
        
        
        for(int i=0;i<26;i++){
            if(counter[i][i]){
                ans+=2;
                break;
            }
        }
        
        
        return ans;
    }


    int main(){

        vector<string> words = {"aa", "bb", "aa", "cb", "bc"};
        cout << longestPalindrome(words) << endl;
    }