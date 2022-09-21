#include<bits/stdc++.h>
using namespace std;


    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n= queries.size();
        int m = nums.size();
        
            int  sum=0;
            for(int j=0;j<m;j++){
                // cout<<nums[j]<<" "<<(nums[j]&1)<<" "<<endl;
                if(!(nums[j]&1)) sum=sum+nums[j];
            }
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int ind = queries[i][1];
            if(!(nums[ind]&1)) sum-=nums[ind];
            nums[ind]= nums[ind]+queries[i][0];
            if(!(nums[ind]&1)) sum+=nums[ind];
            
            ans.push_back(sum);
        }
        
        return ans;
    }



int main(){


    vector<int> nums = {1,2,3,4};
    vector<vector<int>> queries = {
        {1,0},
        {-3,1},
        {-4,0},
        {2,3}};
//  Input: nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
// Output: [8,6,2,4]

    vector<int> ans = sumEvenAfterQueries(nums, queries);

    for(auto it:ans)
        cout << it << " ";
}