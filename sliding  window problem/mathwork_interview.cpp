#include<bits/stdc++.h>
using namespace std;


pair<int,int> findLen(string str,int k,string s){
    unordered_map<char, int> normalChar;
    string abc = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0;i<abc.length();i++){
        if(s[i]=='0')
            normalChar[abc[i]] = 1;
    }

    int normalCount = 0;
    int maxLen = 0;
    int start_ind;
    int end_ind;

    int i = 0;
    for (int j = 0;j<str.length();j++){
        if(normalChar.find(str[j])!=normalChar.end()){
            normalCount++;
        }

        if(normalCount<=k){
            maxLen = max(maxLen, j - i + 1);
            start_ind = i;
            end_ind = j;
        }

        if(normalCount>k){
            while(normalCount>k){
                if(normalChar.find(str[i])!=normalChar.end()){
                    normalCount--;
                }
                i++;
            }

            if(normalCount==k){
                maxLen = max(maxLen, j - i + 1);
                start_ind = i;
                end_ind = j;
            }
        }
    }

    return {start_ind, end_ind};
}



int main(){
    string str = "giraffe";
    int k = 3;
    string s = "0111100111111111101111111";

    pair<int, int> p = findLen(str, k, s);

    for(int i=p.first; i<=p.second; i++){
        cout << str[i];
    }
}