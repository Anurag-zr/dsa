#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums,int start,int mid,int end){
    int n = mid - start + 1;
    int m = end - mid;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n;i++){
        a[i] = nums[start+i];
    }

    for (int i = 0; i < m;i++){
        b[i] = nums[mid + 1+i];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n && j<m){
        if(a[i]<=b[j]){
            nums[k] = a[i];
            i++;
        }
        else{
            nums[k] = b[j];
            j++;
        }

        k++;
    }

    while(i<n){
        nums[k] = a[i];
        i++;
        k++;
    }

    while(j<m){
        nums[k] = b[j];
        j++;
        k++;
    }

    a.clear();
    b.clear();
}

void mergeSort(vector<int> &nums,int n){
    for (int width = 1; width < n;width = 2*width){
        for (int left_start = 0; left_start < n; left_start+=2*width){

            int mid = min(left_start + width - 1, n - 1);
            int right_end = min(left_start + 2 * width - 1, n - 1);

            // cout << left_start << " " << mid << " " << right_end << endl;
            merge(nums, left_start, mid, right_end);
        }
    }
}

int main(){
    // vector<int> nums = {-23, -434, 45, 2, 35, 4, 63};
    vector<int> nums = {-4, 234, 34, 646, -34, 2, 45, -34, 29, -23, 98, -39};
    int n = nums.size();
    mergeSort(nums, n);
    for(auto it:nums){
        cout << it << " ";
    }
}