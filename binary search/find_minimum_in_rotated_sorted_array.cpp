#include<bits/stdc++.h>
using namespace std;


//assumption: there is an assumption that every element
//in array is distinct otherwise it's not going to work 
//I dont know answer yet when array have distinct number

//Time complexity: O(logn)

int findminimum(vector<int> arr, int n){
    int start = 0;
    int end = n - 1;

    while(start<=end){
        int mid = start + (end - start) / 2;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;

        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]){
            return mid;
        }
        else if(arr[mid]<=arr[end]){
            end = mid - 1;
        }
        else if(arr[mid]>=arr[start]){
            start = mid + 1;
        }
    }

    return 0;
}

int main(){
    vector<int> arr = {50, 54, 60, 4, 6, 20, 35, 41, 49};
    cout << "minimum ele index :" << findminimum(arr, arr.size()) << endl;
}