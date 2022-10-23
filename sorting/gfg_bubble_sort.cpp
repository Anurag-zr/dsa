#include <bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}


void bubbleSort(vector<int> &nums){
    int n= nums.size();
    for (int i = 0; i < n - 1;i++){
    //no of iteration 
    // we need to perform
        for(int j= 0; j < n-i-1;j++){
            //here largest value is 
            //coming to last index at every iteration 
            if(nums[j]>nums[j+1]){
                swap(nums[j], nums[j + 1]);
            }

        }
    }
}

int main(){
    vector<int> nums = {34, 22, -4, 6, 2, -5};
    bubbleSort(nums);
    for(auto it:nums){
        cout << it << " ";
    }
}