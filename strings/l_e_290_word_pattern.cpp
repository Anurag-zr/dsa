#include<bits/stdc++.h>
using namespace std;


    bool wordPattern(string pattern, string s) {
     
        unordered_map<char,int> patternToInt;
        unordered_map<string,int> textToInt;
        stringstream ss(s);
        int i=0;
        int n = pattern.length();
        for(string word;ss>>word;i++){
        
            if(i==n) return false;
            if(patternToInt[pattern[i]]!=textToInt[word]) return false;
            patternToInt[pattern[i]]=textToInt[word]=i+1;
        }
        return i==n;
    }


    int main(){
        /*
        Input: pattern = "abba", s = "dog cat cat dog"
Output: true
    
    */

        string pattern = "abbba";
        string s = "dog cat cat cat dog";

        cout << wordPattern(pattern, s) << endl;
    }