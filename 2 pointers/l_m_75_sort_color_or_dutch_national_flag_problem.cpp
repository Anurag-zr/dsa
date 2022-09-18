#include<bits/stdc++.h>
using namespace std;


    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low = 0;
        int  mid = 0;
        int high = n-1;
        
        while(mid<=high){
            
            if(nums[mid]==0){
                swap(nums[mid++],nums[low++]);
            }
            
            else if(nums[mid]==1){
                mid++;
            }
            
            else{ //nums[mid]==2
                swap(nums[mid],nums[high--]);
            }
        }
    }


int main(){
    vector<int> nums = {1, 1, 0, 0, 1, 2, 2, 0, 1, 0, 2, 2};

    sortColors(nums);

    for(auto ele:nums)
        cout << ele << " ";
}