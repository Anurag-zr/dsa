#include <bits/stdc++.h>
using namespace std;


int bs(vector<int> arr,int start,int end,int k){
    while(start<=end){
        int mid = start + (end - start) / 2;
        if(k==arr[mid]){
            return mid;
        }
        else if(k<arr[mid]){
            end=mid -1;
        }
        else if(k>arr[mid]){
            start = mid + 1;
        }
    }

    return -1;
}

int solve(vector<int> arr, int k){

    int start = 0;
    int end = 1;
  

   while(k>arr[end]){
       start = end;
       end = end * 2;
   }

    return bs(arr,start,end,k);
}

int main(){
    //pretend last index not known as it is an infinite array
    vector<int> arr = {2, 4, 6, 9, 14, 50, 99, 232, 343, 764, 1000};
    // int k = 343;
    int k = 999;

    cout << solve(arr, k) << endl;
}