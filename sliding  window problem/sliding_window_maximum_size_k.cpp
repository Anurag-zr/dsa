#include <bits/stdc++.h>
using namespace std;

int main(){

    //brute force 
    //status TLE
// time complexity  n^2
    // vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> nums = {9,10,9,-7,-4,-8,2,-6};
    int k = 5;
    vector<int> ans;
    int n = nums.size();
     
    // for (int i = 0; i < n - k + 1; i++)
    // {
    //     int max = INT_MIN;
    //     // cout<<max<<endl;
    //     for (int j = i; j < i + k; j++)
    //     {
    //         if (max < nums[j])
    //         {
    //             max = nums[j];
    //         }
    //     }

    //     ans.push_back(max);
    //     }

    //     for(auto it:ans){
    //         cout << it << " ";
    //     }


    //sliding window approach 
        deque<int> dq;
        
        int i=0;
         for(int j=0;j<n;j++){
            while(dq.size()>0 && dq.back()<nums[j]){
                dq.pop_back();
            }
            
            dq.push_back(nums[j]);
            
            if(j-i+1==k){
                ans.push_back(dq.front());
                if(dq.front()==nums[i]){
                    dq.pop_front();
                }
                
                i++;
            }
    
        }

       for(auto i:ans){
           cout << i << " ";
       }

}