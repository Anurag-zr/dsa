#include<bits/stdc++.h>
using namespace std;

int findMaxInBitonic(vector<int> nums){
    int start = 0;
    int end =nums.size() - 1;

    while(start<=end){
        int mid= start + (end - start) / 2;

        if(nums[mid]>nums[mid-1] &&  nums[mid]>nums[mid+1] ){
            return mid;
        }
        else if(nums[mid]<nums[mid-1]){
            end = mid - 1;
        }
        else if(nums[mid]<nums[mid+1]){
            start = mid + 1;
        }
    }

    return -1;
}

int incBS(vector<int> arr,int target,int start,int end){
  while(start<=end){
    int mid = start + (end - start) / 2;

    if(arr[mid] == target){
        return mid;
    }
    else if(target<arr[mid]){
        end = mid -1;
    }
    else if(target>arr[mid]){
        start = mid + 1;
  }

}

return -1;
}

int decBS(vector<int> arr,int target,int start,int end){
 while(start<=end){
    int mid = start + (end - start) / 2;

    if(arr[mid] == target){
        return mid;
    }
    else if(target<arr[mid]){
        start = mid + 1;
    }
    else if(target>arr[mid]){
        end= mid - 1;
  }
}

return -1;
}

int main(){
    vector<int> nums = {1, 4, 5, 7, 8, 24, 23, 11, 2};
    int target = 15;

    int maxIndex = findMaxInBitonic(nums);

    int l = incBS(nums, target,0,maxIndex);
    if(l!=-1)
        cout << l << endl;
    else
        cout << decBS(nums, target,maxIndex+1,nums.size()-1) << endl;
}