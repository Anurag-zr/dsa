#include <bits/stdc++.h>
using namespace std;

int findMinDiffElement(vector<int> arr,int target){
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid]==target){
            start = mid + 1;
            end = mid;
        }
        else if(target<arr[mid]){
            end = mid - 1;
        }
        else if(target>arr[mid]){
            start = mid + 1;
        }
    }

    if(abs(target-arr[start])<abs(target-arr[end])){
        return arr[start];
    }
     return arr[end];
}


int main(){
    vector<int> arr = {1, 3, 4, 6, 7, 12, 14, 16};
    // int target = 13;
    // int target = 14;
    int target = 10;


    cout << findMinDiffElement(arr, target) << endl;
}