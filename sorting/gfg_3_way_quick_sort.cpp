#include<bits/stdc++.h>
using namespace std;


void partition(int arr[],int low,int high,int &i,int &j){
    int pivot = arr[high];
     i = low - 1;
     j = high + 1;

    int k = low;

    while(k<j){
        if(arr[k]<pivot){
            i++;
            swap(arr[i], arr[k]);
            k++;
        }
        else if(arr[k]>pivot){
            j--;
            swap(arr[j], arr[k]);
        }
        else{
            k++;
        }
    }
}

void threeWayQuickSort(int arr[],int low,int high){

    if(low>=high)
        return;

    int m,n;

    partition(arr, low, high,m,n);
    threeWayQuickSort(arr, low, m);
    threeWayQuickSort(arr, n, high);
}

int main(){
    int arr[] = {4,4,4,2,2,4,1,1,1,2,2,2,4,4,4,2,2,1,1,3,6,7,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int low = 0;
    int high = n - 1;
    threeWayQuickSort(arr, 0, n - 1);

    for(auto i: arr){
        cout << i << " ";
    }
}