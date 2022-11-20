#include<bits/stdc++.h>
using namespace std;

    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        
        for(auto num:nums){
            if(st.find(num)!=st.end()) //exist
                return true;
            
            st.insert(num);
        }
        
        return false;
    }


int main(){
    vector<int> nums = {1, 2, 4, 5, 7, 4, 2, 1};
    cout << containsDuplicate(nums) << endl;
}


