#include<bits/stdc++.h>
using namespace std;

//     vector<int> dailyTemperatures(vector<int>& temperatures) {
// //         bruteforce
// //         int n= temperatures.size();
// //         vector<int> ans(n,0);
        
// //         for(int i=0;i<n;i++){
// //             for(int j=i;j<n;j++){
// //                 if(temperatures[j]>temperatures[i]){
// //                     ans[i] = j-i;
// //(                     break;
// //                 }
// //             }
// //         }
        
// //         return ans;
//     }
    //monotonic stack;
    vector<int> dailyTemperatures(vector<int> &temperatures){
        int n = temperatures.size();
        vector<int> ans(n,0); 
        stack<pair<int,int>> stk;
        stk.push({temperatures[n-1],n-1});
        for(int i = n-2;i>=0;i--){
            while(stk.size() && stk.top().first<=temperatures[i]) stk.pop();
            
            if(stk.size()) ans[i] =(stk.top().second - i);
            
            stk.push({temperatures[i],i});
        }
        
        
        return ans;
    }

int main(){

        vector<int> temperatures = {34, 23, 355, 343, 34, 23, 12, 344, 25, 667};
        vector<int> ans= dailyTemperatures(temperatures);

        for(auto i:ans){
            cout << i << " ";
        }
}