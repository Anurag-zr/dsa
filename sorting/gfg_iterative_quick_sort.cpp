#include<bits/stdc++.h>
using namespace std;

int  partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}



void iterativeQuickSort(int arr[],int low, int high){
    int stack[high - low + 1];
    int top = -1;

    stack[++top] = high;
    stack[++top] = low;

    while(top>=0){
        int l = stack[top--];
        int h = stack[top--];

        int pivot = partition(arr, l, h);

        if(pivot+1<h){
            stack[++top] = h;
            stack[++top] = pivot + 1;
        }

        if(pivot-1>l){
            stack[++top] = pivot - 1;
            stack[++top] = l;
        }
    }
}



int main(){
    int arr[] = {-223, 34, 45, -34, 12, -65, 46, 86, -34, 930, 93, -53};
    int n = sizeof(arr)/sizeof(arr[0]);

    iterativeQuickSort(arr, 0, n - 1);

    for(auto i:arr){
        cout << i << " ";
    }
}