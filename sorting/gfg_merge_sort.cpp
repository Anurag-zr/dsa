#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int start, int mid, int end){
    int n = mid-start+1;  // length of left subarray
    int m = end - mid;    // length of right subarray
    vector<int> leftArr(n);
    vector<int> rightArr(m);

    for (int i = 0; i < n;i++){
        leftArr[i] = nums[start+i];
    }

    for (int i = 0; i < m;i++){
        rightArr[i] = nums[mid+1+i];
    }

    int i = 0; // ptr to leftArr
    int j = 0; //ptr to rightArr
    int k = start; //ptr to  nums array where we are going ot store sorted arr

    while (i < n && j<m){
        if(leftArr[i]<=rightArr[j]){
            nums[k]= leftArr[i];
            i++;
        }
        else{
            nums[k]=rightArr[j];
            j++;
        }
        k++;
    }

    if(i==n && j<m){
        while(j<m){
            nums[k] = rightArr[j];
            j++;
            k++;
        }
    }

    if(j==m && i<n){
        while(i<n){
            nums[k]=leftArr[i];
            i++;
            k++;
        }
    }

    leftArr.clear();
    rightArr.clear();
}

void mergeSort(vector<int> &nums,int start,int end){

    if(start>=end)
        return;

    int mid = start + (end - start) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, mid, end);
}

int main(){
    vector<int> nums = {-43, 4, -34, 3, 45, 10, 232, -3};
    mergeSort(nums, 0, nums.size() - 1);
    for(auto it:nums){
        cout << it << " ";
    }
}