
/*

str ="abc";
 
 all possible subsequence 
  " " 
  "a"
  "b"
  "c"
  "ab"
  "bc"
  "ac"
  "abc"

  n=3 , possible subsequence 2^3 = 8

  this can be done using power set in O(2^n*n) time complexity

  here we solve it using recursion
  
  nums =[1,2,2,2,3,3] and same subset is allowed only once

  then all possible subsequence 
  " " 
  1
  2
  3
  12
  22
  23
  33
  123
  122
  133
  222
  233 and many more ....  less than 2^6


*/

#include <bits/stdc++.h>
using namespace std;

void findSubsequence(int ind,vector<int> &ds,vector<int> &nums,vector<vector<int>> &ans){
    ans.push_back(ds);

    for (int i = ind;i < nums.size(); i++)
    {
        if(i>ind && nums[i] == nums[i-1]) continue;
        ds.push_back(nums[i]);
        findSubsequence(i + 1, ds, nums, ans);
        ds.pop_back();
    }
}

int main(){
    vector<int> nums = {1, 2, 2, 2, 3, 3};
    vector<int> ds;
    vector<vector<int>> ans;

    findSubsequence(0,ds,nums,ans);

    for(auto it: ans){
        for(auto it1:it){
            cout << it1 << " ";
        }
        cout << endl;
    }
}