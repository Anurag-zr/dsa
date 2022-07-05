#include <bits/stdc++.h>
using namespace std;

    int longestConsecutive(vector<int>& nums) {
      unordered_map<int,int> umap;
        for(auto i:nums){
            umap[i]++;
        }
        
        int maxlen =0;
        for(int i=0;i<nums.size();i++){
            if(umap.find(nums[i]-1)==umap.end()){
             int currentnum = nums[i];
             int currentlen = 1;
                while(umap.find(currentnum+1)!=umap.end()){
                    currentnum++;
                    currentlen++;
                }
                
                maxlen = max(maxlen,currentlen);
            }
        }
    
     return maxlen;
    }

int main(){
    vector<int> nums = {100, 101, 99, 4, 2, 1, 3};
    cout<<longestConsecutive(nums)<<endl;
}