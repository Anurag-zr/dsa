#include<bits/stdc++.h>
using namespace std;


    void helper(int ind,vector<int> &ds,int &k,vector<int> &ans){
        if(ind == ds.size()){
            int num=0;
            for(int i=0;i<ds.size();i++){
                num = 10*num+ds[i];
            }
            ans.push_back(num);
            return;
        }
        
        
        for(int i=0;i<=9;i++){
            if(abs(ds[ind-1]-i)==k){
                ds[ind]=i;
                helper(ind+1,ds,k,ans);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ds(n);
        vector<int> ans;
        
        int ind =0;
        for(int i=1;i<=9;i++){
            ds[ind]=i;
            helper(ind+1,ds,k,ans);
        }
        
        
        return ans;
    }


int main(){
    int n=3;// length of num
    int k=7;// consecutive difference

    vector<int> ans = numsSameConsecDiff(n, k);

    for(auto &it:ans){
        cout << it << " ";
    }
}