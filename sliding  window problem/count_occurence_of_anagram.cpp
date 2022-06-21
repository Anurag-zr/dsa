#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string, int, int, string);

//bruteforce : t.c n^2
int countOcurrenceofAnagram(string txt,string ptr){
    int count = 0;
    int k=ptr.size();
    for (int i = 0;i<=txt.length()-ptr.length()+1;i++){
        if(isAnagram(ptr,i,i+k-1,txt)){
            count++;
        }
    }

    return count;
}

bool isAnagram(string ptr,int startIdx,int endIdx,string txt){
    unordered_map<char, int> ptrcount_map;
    unordered_map<char, int> txtcount_map;

    for(auto it: ptr){
        ptrcount_map[it] += 1;
    }

    for (int i = startIdx;i<=endIdx;i++){
        txtcount_map[txt[i]] += 1;
    }

    for (auto it:ptr){
        if(ptrcount_map[it]!=txtcount_map[it]){
            return false;
        }
    }
    cout << txt.substr(startIdx,ptr.size())<< endl;
    return true;
}

int main(){

    string txt = "forxxorfxdofr";
    string ptr = "for";

    cout << countOcurrenceofAnagram(txt, ptr) << endl;
}