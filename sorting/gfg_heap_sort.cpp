#include<bits/stdc++.h>
using namespace std;


void heapify(vector<int> &arr,int n,int index){

    int largest = index;
    int l = 2 * index + 1;
    int r = 2 * index + 2;

    if(l<n && arr[l]>arr[largest]){
        largest = l;
    }

    if(r<n && arr[r]>arr[largest]){
        largest = r;
    }

    if(largest !=index){
        swap(arr[largest], arr[index]);
        heapify(arr,n,largest);
    }
}




void heapSort(vector<int> &arr,int n){

    for (int i = n / 2 - 1; i >= 0;i--){
        heapify(arr,n, i);
    }

    for (int i = n - 1; i >= 0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}


int main(){
    vector<int> arr = {-43, 23, 56, 87, 45, -23, 47, -778, -2, 40, 07, -234, -4, 76};
    int n = arr.size();

    heapSort(arr, n);

    for(auto i:arr){
        cout << i << " ";
    }
}