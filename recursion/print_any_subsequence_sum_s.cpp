#include <bits/stdc++.h>
using namespace std;

bool print(int i, vector<int> &ds,int s, int arr[], int n , int sum){
   if(i == n ){
       if(s == sum){
           for(auto it: ds)
               cout << it << " ";
           return true;
       }

       return false;
   }

   ds.push_back(arr[i]);
   if(print(i+1,ds, s+arr[i],arr,n, sum)== true) return true;
   ds.pop_back();
   if(print(i+1,ds, s, arr, n, sum)== true) return true;

   return false;
}

int main(){
    int arr[] = {1, 2, 1};
    int n = 3;
    vector<int> ds;
    int sum = 3;
    int s = 0;

    print(0, ds, s, arr, n, sum);
}