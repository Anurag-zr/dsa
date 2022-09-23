#include<bits/stdc++.h>
using namespace std;


    int concatenatedBinary(int n) {
        long ans=0;int mod =1e9+7;int len=0;
        
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0) len++;  //if i is a power of 2
            ans= ((ans<<len)+i)%mod;
        }
        
        return ans;
    }


int main(){
    int n = 3;
    cout << concatenatedBinary(n);
}