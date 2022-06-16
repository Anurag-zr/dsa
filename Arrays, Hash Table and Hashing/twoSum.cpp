#include<bits/stdc++.h>
using namespace std;

/*

leetcode easy

nums[] = {2,11,3,4} target =13

so,return only 2 numbers indecies
[0,1] as nums[0]+nums[1] = 13


tags: array, hash table, unordered_map,leetcode

*/

vector<int> twoSum(vector<int> &nums,int target){
    vector<int> ans;
    unordered_map<int, int> u_mp;

    for (int i = 0;i<nums.size(); i++){

        if(u_mp.find(target-nums[i]) != u_mp.end()){
            ans.push_back(u_mp[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }

        u_mp[nums[i]] = i;
    }

    return ans;
}

int main(){
    vector<int> nums={2,7,11,15};
    int target = 9;

    vector<int> ans =  twoSum(nums, target);

    for(auto it:ans){
        cout << it << " ";
    }


}


