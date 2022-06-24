#include <bits/stdc++.h>
using namespace std;

//sliding window approach approach
// time complexity O(n) 
//this approach don't work for negative no.

int largestSubarray(vector<int> &nums,int k){
    int maxi = INT_MIN;
    int sum = 0;

    int i = 0;
    for (int j = 0;j<nums.size();j++){
      sum+=nums[j];

      if(sum==k){
          maxi = max(maxi, j - i + 1);
      }
      else if(sum>k){
        while(sum>k){
            sum = sum - nums[i];
            i++;
        }
         if(sum == k){
              maxi = max(maxi, j-i+1);
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

    cout << largestSubarray(nums, k) << endl;
}