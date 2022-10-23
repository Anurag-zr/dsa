#include<bits/stdc++.h>
using namespace std;


void insertionSort(vector<int> &nums){

    int n = nums.size();
    for (int i = 1; i < n;i++){

        int key = nums[i];
        int j = i-1;
        while (j >= 0 && nums[j]>key){
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = key;
    }
}

int main(){
    vector<int> nums = {-4, -45, 39, 30, -34, 12, 0};
    insertionSort(nums);
    for(auto it:nums){
        cout << it << " ";
    }
}