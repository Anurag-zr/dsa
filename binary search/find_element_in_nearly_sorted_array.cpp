#include<bits/stdc++.h>
using namespace std;

int search(vector<int> arr,int ele){
    int n = arr.size();
    int l = 0;
    int r = n - 1;

    while(l<=r){
        int mid = l + (r - l) / 2;

        if(ele == arr[mid]){
            return mid;
        }
        else if(mid -1 >= l  && ele == arr[mid-1]){
            return mid - 1;
        }
        else if(mid+1 <=r  && ele == arr[mid+1]){
            return mid + 1;
        }

        else if(ele<arr[mid]){
            r = mid - 2;
        }
        else if(ele>arr[mid]){
            l = mid + 2;
        }
    }

    return -1;
}

int main(){
    vector<int> arr = {2, 7, 5, 30, 10, 50};
    int ele = 10;

    cout << search(arr, ele) << endl;
}