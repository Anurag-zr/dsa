#include<bits/stdc++.h>
using namespace std;

        
    bool isUgly(int n) {
        if(n==1) return true;
        if(n<1) return false;
        
        for(int i=2;i<6;i++){
            while(n%i==0) n=n/i;
        }
        
        return n==1;
    }

int main(){
  cout<<isUgly(40)<<endl;
  cout<<isUgly(-2)<<endl;
  cout<<isUgly(0)<<endl;
  cout<<isUgly(1)<<endl;
  cout<<isUgly(34)<<endl;
  cout<<isUgly(456)<<endl;
  cout<<isUgly(23)<<endl;
}