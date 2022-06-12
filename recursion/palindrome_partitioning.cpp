/*

str ="aabb"
 
 possible palindromic partitioning
 [{a,a,b,b},
  {a,a,bb},
  {aa,b,b},
  {aa,bb}]

  */

 #include<bits/stdc++.h>
 using namespace std;
 bool isPalindrome(string, int, int);

 void findPalindromicPartition(int ind,string str,vector<string> &ds,vector<vector<string> > &ans){
    if(ind == str.size()){
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i<str.size(); i++) {
        if(isPalindrome(str,ind,i)){
            ds.push_back(str.substr(ind, i - ind + 1));
            findPalindromicPartition(i+1,str,ds,ans);
            ds.pop_back();
        }
    }
 }

 bool isPalindrome(string str,int startIdx,int endIdx){
    while(startIdx<=endIdx){
        if(str[startIdx]!=str[endIdx]){
            return false;
        }
        startIdx++;
        endIdx--;
    }

    return true;
 }

 int main(){

   string str = "aabb";
    vector<vector<string>> ans;
    vector<string> ds;

    findPalindromicPartition(0, str, ds, ans);

    for(auto &it: ans){
        for(auto &it1 : it){
            cout << it1 << " ";
        }
        cout << endl;
    }
 }
  