#include<bits/stdc++.h>
using namespace std;

   bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int charptr1 =0;
        int charptr2 =0;
        
        int wordptr1 =0;
        int wordptr2 = 0;
        
        while(wordptr1<word1.size() && wordptr2<word2.size()){
            if(word1[wordptr1][charptr1++]!=word2[wordptr2][charptr2++]) return false;
            
            if(charptr1==word1[wordptr1].size()){ wordptr1++; charptr1=0;}
            if(charptr2==word2[wordptr2].size()){wordptr2++; charptr2=0;}
        
        }
        
        return wordptr1 ==word1.size() && wordptr2 == word2.size();
    }

int main(){
    // ["abc", "d", "defg"]
// ["abcddefg"]

    vector<string> word1 = {"abc", "d", "defg"};
    vector<string> word2 = {"abcddefg"};

    cout << arrayStringsAreEqual(word1, word2) << endl;
}