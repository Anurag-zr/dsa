#include<bits/stdc++.h>
using namespace std;


class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
int count(vector<int> arr, int n, int x) {
	 if(n==1){
        if(arr[0]==x){
            return 1;
        }
        else{
            return 0;
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
    
    if(firstoccurence == -1){
        return 0;
    }else
    return lastoccurence-firstoccurence+1;
	}
};


int main() {
    vector<int> arr = {1, 2, 3, 10, 10, 10, 100, 230};
    Solution obj;

    cout << obj.count(arr, arr.size(), 10) << endl;
}
