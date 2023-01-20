#include<bits/stdc++.h>
using namespace std;

    void helper(int ind,vector<int> &ds,vector<vector<int>> &ans,vector<int> &nums){
        if(ds.size()>=2) ans.push_back(ds);
        
        
        set<int> hash;
        for(int i=ind;i<nums.size();i++){
            if((ds.empty() || nums[i]>=ds.back()) && hash.find(nums[i])==hash.end()){
                ds.push_back(nums[i]);
                helper(i+1,ds,ans,nums);
                ds.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        
        vector<int> ds;
        
        helper(0,ds,ans,nums);
        
        return ans;
    }

int main(){

    /*
    Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
    */

        vector<int> nums = {4, 6, 7, 7};
        vector<vector<int>> ans = findSubsequences(nums);

        for (auto it : ans)
        {
            for (auto i : it)
            {
                cout << i << " ";
            }
            cout << endl;
   }
}