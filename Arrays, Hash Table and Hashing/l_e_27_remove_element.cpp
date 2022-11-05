#include<bits/stdc++.h>
using namespace std;


    int removeElement(vector<int>& nums, int val) {
        int count =0;
        int n=nums.size();
        
        int i=0;
        while(i<n){
            if(nums[i]==val){
                count++;
                int j=i;
                while(j+1<n){
                    nums[j]=nums[j+1];
                    j++;
                }
                n--;
            }
            else{
                i++;
            }
        }
        
        return nums.size()-count;
    }

int main(){
    vector<int> nums = {2,4,6,2,2,5,2,2,5,6};
    int val = 2;
    int k = removeElement(nums, val);
    for (int i = 0; i < k;i++){
        cout << nums[i] << endl;
    }
}