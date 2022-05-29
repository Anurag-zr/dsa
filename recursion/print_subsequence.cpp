#include <bits/stdc++.h>
using namespace std;

void printSubsequence(int ind, vector<int> &ans, int arr[], int n){
 
 if(ind == n){
     for(auto it: ans){
         cout << it << " ";
     }
     if(ans.size() == 0){
         cout << "{ }"
              << " ";
     }
     cout << endl;
     return;
 }

//take or pick  this particular index element in subsequence
 ans.push_back(arr[ind]);
 printSubsequence(ind + 1, ans, arr, n);

 //don't pick this particular index element in subsequence
 ans.pop_back();
 printSubsequence(ind + 1, ans, arr, n);

}

int main(){
    int arr[] = {3, 1, 2};
    int n = 3;

    vector<int> ans;

    printSubsequence(0, ans, arr, n);
}