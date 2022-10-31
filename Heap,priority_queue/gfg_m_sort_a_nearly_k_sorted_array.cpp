#include<bits/stdc++.h>
using namespace std;



    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        vector<int> ans(num);
        
        int size = num==K ? K : K+1;
        
        priority_queue<int,vector<int>,greater<int>> pq(arr,arr+size);
        
        // while(!pq.empty()){
        //     cout<<pq.top()<<" "<<endl;
        //     pq.pop();
        // }
        
        int j=0;
        for(int i=K+1;i<num;i++){
            ans[j++] = pq.top();
            // cout<<pq.top()<<" ";
            pq.pop();
            pq.push(arr[i]);
        }
        
        while(!pq.empty()){
            ans[j++] = pq.top();
            pq.pop();
        }
        
        return ans;
    }


int main(){

    int arr[] = {23, -35, -348, 394, 29, 06, 95, -2};
    int k = 3;

    vector<int> ans = nearlySorted(arr, sizeof(arr)/sizeof(arr[0]), k);
    for(auto i:ans){
        cout << i << " ";
    }
}