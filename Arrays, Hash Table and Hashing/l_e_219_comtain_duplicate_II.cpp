#include<bits/stdc++.h>
using namespace std;

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
     unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
                if(umap.find(nums[i])!=umap.end()){
                    if(abs(i-umap[nums[i]])<=k) return true;
                }
            
                    umap[nums[i]]=i;
                
        }
        
        return false;
    }

int main(){
    vector<int> nums={1,0,1,1};
    int k=1;

    cout << containsNearbyDuplicate(nums, k) << endl;
}