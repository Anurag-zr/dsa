#include<bits/stdc++.h>
using namespace std;

    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> v(nums.begin(),nums.end());
        sort(v.begin(),v.end());
        
        int closestSum = nums[0]+nums[1]+nums[2];
        
        int n= nums.size();
        for(int i=0;i<n-2;i++){
            int first = i;
            if(first>0 && v[first]==v[first-1]) continue;
            int second = first+1;
            int last = n-1;
            
            while(second<last){
                int curSum = v[first]+ v[second]+v[last];
                if(curSum == target) return curSum;
                else if(abs(target-closestSum)>abs(target-curSum)){
                    closestSum = curSum;
                }
                
                if(curSum>target){
                    last--;
                }
                else{
                    second++;
                }
            }
            
        }
        
        return closestSum;
    }

    int main(){
        vector<int> nums = {-1, 3, 5, 8, -12};
        int target = 2;
        cout << threeSumClosest(nums, target) << endl;
    }