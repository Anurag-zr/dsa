#include<bits/stdc++.h>
using namespace std;

    int findsol(vector<int>& nums) {
      //space optimization technique 
        //build logic using recursion |dp memoization |tabulation then this...
        int n= nums.size();
        int prev1=nums[0];
        int prev2=0;
        int curi;
        
        int pick,notpick;
        
        for(int i=1;i<n;i++){
            //take
            pick = nums[i]+prev2;
            //not take
            notpick = 0+prev1;
            
            curi = max(pick,notpick);
            prev2 = prev1;
            prev1=curi;
        }
        
        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n= nums.size();
        
        if(n==1) return nums[0];
        
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        
        return max(findsol(temp1),findsol(temp2));
    }

int main(){

    //circular array nums[0] and nums[n-1] are adjacent elements 
    vector<int> nums = {2, 3, 2};
    cout << rob(nums) << endl;
}