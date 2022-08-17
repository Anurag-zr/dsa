#include<bits/stdc++.h>
using namespace std;


    int uniqueMorseRepresentations(vector<string>& words) {
      vector<string> d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    
        unordered_set<string> morse;
        
        for(auto s:words){
            string ans;
            for( auto c:s) { 
                ans+=d[c-'a'];
            }
            morse.insert(ans);
        }

        // // unordered_set<string> s;
        // for(auto w:words) {
        //     string code;
        //     for (auto c:w) code+=d[c - 'a'];
        //     s.insert(code);
        // }
        // // return s.size();
        
        
        return morse.size();

    }

    int main(){
        vector<string> words = {"pig", "dig"};
        cout << uniqueMorseRepresentations(words);
    }