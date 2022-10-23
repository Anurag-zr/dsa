#include<bits/stdc++.h>
using namespace std;


void stableSelectionSort(vector<int> &arr){

    int n = arr.size();
    for (int i = 0; i < n - 1;i++){

        int min = i;
        for (int j = i + 1; j < n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }

        int key = arr[min];
        while(min>i){
            arr[min] = arr[min - 1];
            min--;
        }

        arr[i] = key;
    }
}

int main(){
    vector<int> nums = {4, 1, 5, 4, -6, -2};
    stableSelectionSort(nums);
    for(auto it:nums){
        cout << it << " ";
    }
}