#include <bits/stdc++.h>
using namespace std;

int largestSubarray(vector<int> &nums,int k, vector<int> &ans){
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0;i<nums.size();i++){
        sum = 0;
        for (int j = i;j<nums.size();j++){
            sum += nums[j];
          
            if(sum == k){
                if (maxi < j - i + 1){
                    ans.clear();
                    for (int k = i; k <= j;k++){
                        ans.push_back(nums[k]); 
                    }
                    maxi = j - i + 1;
                }
                    break;
            }
            else if(sum>k){
                break;
            }
        }
    }

    return maxi;
}

int main(){
    // vector<int> nums = {4, 1, 1, 1, 2, 3, 5};
    // vector<int> nums = {1,2,3,7,5};
    vector<int> nums = {1,1,1,4};
    int k = 4;
    vector<int> ans;
    cout << largestSubarray(nums, k,ans) << endl;

    for(auto i: ans){
        cout << i << " ";
    }
}