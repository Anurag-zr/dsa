#include<bits/stdc++.h>
using namespace std;

    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivot = arr[high];
       int i = low-1;
       
       for(int j=low;j<=high-1;j++){
           if(arr[j]<pivot){
               i++;
               swap(arr[i],arr[j]);
           }
       }
       
       swap(arr[i+1],arr[high]);
       return i+1;
    }


     void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low>=high) return;
        
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
    





int main(){

    int arr[10] = {-3459, -34, 39, 2, -84, 39, 28, 20, 04, -3};
    int low = 0;
    int high = 9;

    quickSort(arr, low, high);

    for(auto i:arr){
        cout << i << " ";
    }
}