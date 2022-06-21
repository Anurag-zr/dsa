#include <bits/stdc++.h>
using namespace std;

// brute force: time complexity is n^2

// vector<int> printFirstNegativeInteger(vector<int> &nums,int n,int k){
//         vector<int> ans;
//     int firstNegNo=0;
    
//     for(int i=0;i<=n-k;i++){
//         firstNegNo=0;
//         for(int j=i;j<i+k;j++){
//             if(nums[j]<0){
//                 firstNegNo = nums[j];
//                 break;
//             }
//         }
        
//         ans.push_back(firstNegNo);
//     }
                                  
                                  
//     return ans;                                             
//  }

// optimal sliding window approach: timme complexity is not
// use of additional data structue deque, same as vector but you can push and pop
// from both ends.

vector<int> printFirstNegativeInteger(vector<int> &nums,int n,int k){
    vector<int> ans;
    deque<int> dq;
    
    for (int i=0, j = 0; j < n;j++){
        if(nums[j]<0){
            dq.push_back(nums[j]);
        }

        if(j-i+1 == k){
            // for(auto it:dq){
            //     cout << it << " ";
            // }
            // cout << endl;
            if(dq.size()==0){
                ans.push_back(0);
            }
            else{
                int num = dq.front();
                ans.push_back(num);

                if(num == nums[i]){
                    dq.pop_front();
                }
            }

            i++;
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {-8, 2, 3, -6, 10};
    int k = 2;
    vector<int> ans = printFirstNegativeInteger(nums,nums.size(),k);

    for(auto &it:ans){
        cout << it << " ";
    }
}