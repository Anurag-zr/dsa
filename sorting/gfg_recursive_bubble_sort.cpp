#include<bits/stdc++.h>
using namespace std;


void recursiveBubbleSort(int n,vector<int> &nums){
    if(n==1)
        return;

    int count = 0;
    for (int i = 0; i < nums.size() - 1;i++){
        if(nums[i]>nums[i+1]){
            swap(nums[i], nums[i + 1]);
            count++;
        }
    }

    if(count==0)
        return;

    recursiveBubbleSort(n - 1, nums);
}

int main(){
    vector<int> nums = {30, -2, -5, 90, 34, -3, 2};
    int n = nums.size();
    recursiveBubbleSort(n-1, nums);
    for(auto it:nums){
        cout << it << " ";
    }
}