#include<bits/stdc++.h>
using namespace std;

    bool increasingTriplet(vector<int>& nums) {
        
        int small = INT_MAX,big = INT_MAX;
        for(int n:nums){
            if(n<=small) small =n;
            else if(n<=big) big = n;
            else return true;
        }
        
        return false;
    }


int main(){
   vector<int> nums ={ 2,4 ,-1, 0,-4,6};
   cout << increasingTriplet(nums) << endl;
}