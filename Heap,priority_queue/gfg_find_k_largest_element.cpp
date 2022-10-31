#include<bits/stdc++.h>
using namespace std;

	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int> ans(k);
	    
	    priority_queue<int,vector<int>,greater<int>> pq(arr,arr+k);
	    
	   // while(!pq.empty()){
	   //     cout<<pq.top()<<endl;
	   //     pq.pop();
	   // }
	   
	   
	   for(int i=k;i<n;i++){
	       int smallest = pq.top();
	       if(arr[i]>smallest){
	           pq.pop();
	           pq.push(arr[i]);
	       }
	   }
	   
	   
	   int index = k-1;
	   while(!pq.empty()){
	       ans[index--]= pq.top();
	       pq.pop();
	   }
	   

	    return ans;
	}


    int main(){
        int arr[] = {-4, 345, 67, -24, 8, 948, -48};
        vector<int> ans = kLargest(arr, sizeof(arr) / sizeof(arr[0]), 3);
        for(auto i:ans){
            cout << i << " ";
        }
    }