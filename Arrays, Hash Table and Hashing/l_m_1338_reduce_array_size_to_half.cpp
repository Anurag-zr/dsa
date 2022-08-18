#include<bits/stdc++.h>
using namespace std;

    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> freq;
        for(auto ele:arr){
            freq[ele]++;
        }
    
        vector<int> counting(n+1);
        for(auto &p:freq) counting[p.second]++; //{0,1,1,0,1,0,0......}
        
        
        int freqcy =n;
        int ans=0;
        int setSize =n;
        while(setSize>n/2 && freqcy>=0){
            
            if(counting[freqcy]==0) freqcy--;
            else{
                setSize-=freqcy;
                ans++;
                counting[freqcy]--;/// from 1 -> 0
            }
        }
        
       return ans;
    }

int main(){
    // [3,3,3,3,5,5,5,2,2,7]
  vector<int> arr = {3,3,3,3,3,5,5,5,2,2,7};
  cout << minSetSize(arr) << endl;
}