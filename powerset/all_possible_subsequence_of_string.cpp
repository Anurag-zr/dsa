
/*

 string "abc"
 all possible subsequence
 " " : null string 
 "a"
 "b"
 "c"
 "ab"
 "bc"
 "ac"
 "abc"

 if n=3  then then 2^n subsequence possible

*/

//program to find all possible subsequence using powerset 

#include<bits/stdc++.h>
using namespace std;


int main(){

  string str = "abc";

  string substr = "";

  vector<string> ans;

  for (int nums = 0; nums < pow(2,str.length()); nums++){
      substr = "";
      for (int i = 0;i<str.length();i++){
          if(nums & (1 << i)){
              substr += str[i];

          }   
      }

      ans.push_back(substr);
  }


  for(auto it: ans){
      cout << it << endl;
  }
}