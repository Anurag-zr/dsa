#include <bits/stdc++.h>
using namespace std;

//stable sort 
//adaptive in nature
// efficient for small input

// 3 parameter
// void recursiveInsertionSort(int ind,int n,vector<int> &nums){
//     if(ind == n)
//         return;

//     int key = nums[ind];
//     int j = ind - 1;

//     while (j >= 0 && nums[j]>key){
//         nums[j + 1] = nums[j];
//         j--;
//     }

//     nums[j + 1] = key;

//     recursiveInsertionSort(ind + 1, n, nums);
// }

// 2 parameter
void recursiveInsertionSort(vector<int> &nums,int n){
    if(n<=1)
        return;

    recursiveInsertionSort(nums, n - 1);

    int key = nums[n - 1];
    int j = n - 2;

    while(j>=0 && nums[j]>key){
        nums[j + 1] = nums[j];
        j--;
    }

    nums[j + 1] = key;
}



int main(){
    vector<int> nums = {-3, -4, -664, 34, 23, -5, 3};
    int n = nums.size();
    // recursiveInsertionSort(1, n, nums);
    recursiveInsertionSort(nums, n);
    for(auto it:nums){
        cout << it << " ";
    }
}