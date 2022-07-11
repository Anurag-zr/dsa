#include<bits/stdc++.h>
using namespace std;

    int peakIndexInMountainArray(vector<int>& arr) {
        int start =0;
        int end =arr.size()-1;
        
        while(start<end){
            int mid = start + (end-start)/2;
            if(arr[mid+1]>arr[mid]){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        
        return start;//or end
    }

int main(){
    //[0,10,5,2]
    vector<int> arr = {0, 10, 5, 2};

    cout <<"peak element: "<< arr[peakIndexInMountainArray(arr)] << endl;
}