#include<bits/stdc++.h>
using namespace std;

    int minimumDeviation(vector<int>& nums) {
        int ans = 1e9;
        int mini = 1e9;
        
        priority_queue<int> pq;
        
        for(auto n: nums){
            if(n%2) n = n*2;
            pq.push(n);
            mini = min(mini,n);
        }
        
        while(pq.top()%2==0){
            ans = min(ans,pq.top()-mini);
            mini = min(mini,pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        
        return min(ans,pq.top()-mini);
    }


int main(){

    vector<int> nums = {4,1,5,20,3};
    cout << minimumDeviation(nums) << endl;
}