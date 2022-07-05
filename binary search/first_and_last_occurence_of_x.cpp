#include<bits/stdc++.h>
using namespace std;

vector<int> find(vector<int> arr, int n , int x )
{
    // code here
    
    if(n==1){
        if(arr[0]==x){
            return {0,0};
        }
        else{
            return {-1,-1};
        }
    }
    
    int start =0;
    int end =n-1;
    int mid;
    int firstoccurence =-1;
    
    while(start<=end){
        mid = start +(end-start)/2;
        if(arr[mid]==x){
            firstoccurence = mid;
            end = mid -1;
        }
        else if(x < arr[mid]){
            end = mid -1;
        }
        else{
            start = mid +1;
        }
    }
    
    start =0;
    end = n-1;
    int lastoccurence =-1;
    
    while(start<=end){
         mid = start +(end-start)/2;
        if(arr[mid]==x){
            lastoccurence= mid;
            start = mid +1;
        }
        else if(x < arr[mid]){
            end = mid -1;
        }
        else{
            start = mid +1;
        }   
    }
    
    return {firstoccurence,lastoccurence};
}




int main(){
    vector<int> arr = {2, 6, 10, 10, 10, 35, 100};
    int x = 10;

    vector<int> ans = find(arr, arr.size(), x);

    cout << ans[0] << "  " << ans[1] << endl;
}