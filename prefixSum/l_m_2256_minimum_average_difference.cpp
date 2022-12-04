#include<bits/stdc++.h>
using namespace std;

    int minimumAverageDifference(vector<int>& nums) {

        long long totalSum=0;    
        int n=nums.size();
        vector<long long> prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        
        totalSum = prefixSum[n-1];
        
        int cur_avg_diff;
        int min_avg_diff = INT_MAX;
        int ans;
        
        long long first_half_sum,sec_half_sum;
        int first_size,sec_size;
        int avg_first,avg_sec;
        
        for(int i=0;i<n;i++){
            first_half_sum=prefixSum[i];
            sec_half_sum = totalSum-prefixSum[i];
            
            first_size=i+1;
            sec_size = n-first_size;
            
            avg_first = first_half_sum/first_size;
            if(sec_size)avg_sec = sec_half_sum/sec_size;
            else avg_sec =0;
            
            cur_avg_diff = abs(avg_first - avg_sec);
            
            // cout<<cur_avg_diff<<" "<<min_avg_diff<<endl;
            if(cur_avg_diff < min_avg_diff){
                min_avg_diff = cur_avg_diff;
                ans = i;
            }
        }
        
        
        return ans;
    }

int main(){
    vector<int> nums={34,32,2,34,6,4,3,26,43};
    cout << minimumAverageDifference(nums) << endl;
}