#include <bits/stdc++.h>
using namespace std;


char findnextAlph(vector<char> arr,char k){
    int n = arr.size();
    int start = 0;
    int end = n-1;

    char ans;

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == k){
            start = mid + 1;
        }
        else if(k<arr[mid]){
            ans = arr[mid];
            end = mid - 1;
        }
        else if(k>arr[mid]){
            start = mid + 1;
        }
    }

  

    return ans;
}


int main(){
    vector<char> arr = {'a', 'c', 'f', 'r', 's', 'x', 'y', 'z'};
    char k = 'f';

    cout << findnextAlph(arr, k) << endl;
}