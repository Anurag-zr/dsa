#include <bits/stdc++.h>
using namespace std;


 int bs(vector<int> &nums,int start,int end,int target){
        while(start<=end){
            int mid = start +(end-start)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        if(n==1 && nums[0]==target){
            return 0;
        }
        else if(n==1 && nums[0]!=target){
            return -1;
        }
        
        int start = 0;
        int end = n-1;
        int minIndex=0;
        
        while(start<=end){
            int mid = start + (end - start)/2;
            
            int next = (mid+1)%n;
            int prev = (mid -1 +n)%n;
            
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                minIndex = mid;
                break;
            }
            
            else if(nums[mid]<=nums[end]){
                end = mid-1;
            }
            else if(nums[mid]>=nums[start]){
                start=mid+1;
            }
        }

        cout << minIndex << endl;

        int foundOnLeft = bs(nums, 0, minIndex - 1, target);
        int foundOnRight = bs(nums, minIndex, n - 1, target);

        if (foundOnLeft != -1)
            return foundOnLeft;
        if (foundOnRight != -1)
            return foundOnRight;
        else
            return -1;        
    }



int main(){
    vector<int> nums = {11, 12, 14, 15, 2, 3, 4, 8};
    int target = 14;

    cout << search(nums, target)<< endl;
}