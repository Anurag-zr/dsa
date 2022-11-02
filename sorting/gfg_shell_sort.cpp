#include <bits/stdc++.h>
using namespace std;


void shellSort(vector<int> &arr,int n){

    for (int gap = n / 2; gap > 0; gap /= 2){
        for (int i = gap; i < n;i++){
            int temp = arr[i];

            int j;
            for ( j = i; j-gap>=0 && arr[j-gap]>temp; j-=gap){
                arr[j] = arr[j-gap];
            }

            arr[j] = temp;
        }
    }
}


int main(){

    vector<int> arr = {-35, 56, 9, 83, 76, 23, -34, -76};
    int n = arr.size();

    shellSort(arr, n);

    for(auto i:arr){
        cout << i << " ";
    }
}