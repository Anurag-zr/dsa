#include<bits/stdc++.h>
using  namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int> &nums){

    for (int i = 0; i < nums.size() - 1;i++){
        int min_idx = i;
        for (int j = i + 1; j < nums.size();j++){
            if(nums[min_idx]>nums[j]){
                min_idx = j;
            }
        }

        // cout << min_idx << endl;
        if(min_idx!=i)
            swap(nums[min_idx], nums[i]);
    }
}

int main(){
    vector<int> nums = {3, 4, 46, -12, 46, 34};
    selectionSort(nums);
    for (auto it:nums){
        cout << it << " ";
    }
}