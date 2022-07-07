#include <bits/stdc++.h>
using namespace std;


int bs(vector<int> arr,int start,int end){
    int res = -1;

    while(start<=end){
        int mid = start + (end - start) / 2;
        if(arr[mid]==1){
            res = mid;
            end = mid - 1;
        }
        else if(arr[mid]==0){
            start=mid +1;
        }

    }

    return res;
}

int solve(vector<int> arr){

    int start = 0;
    int end = 1;
  

   while(1>arr[end]){
       start = end;
       end = end * 2;
   }

   cout << start << " " << end << endl;
   return bs(arr, start, end);
}

int main(){
    //pretend last index not known as it is an infinite array
    vector<int> arr = {0,0,0,0,0,0,1,1,1};
    cout << solve(arr) << endl;
}