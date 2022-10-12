#include<bits/stdc++.h>
using namespace std;

    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //triangle property: sum of any 2 side must be greater than third side;
        
       for(int i= nums.size()-1;i>1;i--){ 
        if(nums[i-2]+nums[i-1]>nums[i]){
          return nums[i]+nums[i-1]+nums[i-2];
        }
       }
        
        return 0;
    }

int main(){
    vector<int> nums = {21, 23, 45, 2, 3, 8};
    cout<<"largest Perimeter:"<<largestPerimeter(nums)<<endl;
}