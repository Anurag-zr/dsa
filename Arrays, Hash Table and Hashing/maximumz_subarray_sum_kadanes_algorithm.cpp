#include <bits/stdc++.h>
using namespace std;

/* 
  kadane's algorithm

*/

int maxSubArray(vector<int> &nums){
  int sum = 0;
  int maxm = nums[0];
  for(int i = 0; i < nums.size();i++){
     sum+=nums[i];
     cout<<"maxm: "<<maxm<<" sum: "<<sum<<endl;
     maxm = max(maxm, sum);
    if(sum<0){
         sum = 0;
     }
  }

  return maxm;
}

int main(){
     
     vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

     cout << maxSubArray(nums) << endl;

}