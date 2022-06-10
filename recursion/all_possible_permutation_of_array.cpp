
/*

nums [1,2,3]
so n! permutation possible for n=3,possible permutation = 6
[1,2,3] 
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]


code to find all possible permutation of string/array using recursion


*/

#include <bits/stdc++.h>
using namespace std;

void findPermutation(int ind, vector<int> &ds,vector<int> &freq,vector<int> &nums, vector<vector<int>> &ans){

     if (ds.size() == nums.size()){
         ans.push_back(ds);
         return;
     }

     for (int i = 0;i<nums.size();i++){
         if(freq[i] == 1) continue;
         freq[i] = 1;
         ds.push_back(nums[i]);
         findPermutation(i + 1, ds, freq, nums, ans);
         freq[i] = 0;
         ds.pop_back();
     }
}

int main(){
    vector<int> nums = {7,9,5,4};
    vector<int> freq(nums.size(),0);
    vector<int> ds;
    vector<vector<int>> ans;

    findPermutation(0, ds, freq, nums, ans);

    for(auto it : ans){
        for(auto it1: it){
            cout << it1 << " ";
        }
        cout << endl;
    }
}