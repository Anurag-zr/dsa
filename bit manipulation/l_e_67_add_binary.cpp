#include<bits/stdc++.h>
using namespace std;

    string addBinary(string a, string b) {
        int carry=0;
        int sum=0;
        
        string ans="";
        
        int i= a.length()-1;
        int j = b.length()-1;
        
        while(i>=0 || j>=0){
            int op1=0,op2=0;
            if(i>=0) op1 = a[i--]-'0';
            if(j>=0) op2 = b[j--]-'0';
            
             sum  = op1 + op2 + carry;
             
            carry = sum>1?1:0;
            sum = sum%2;
            
            // cout<<carry<<" "<<sum<<endl;
            
            ans+=(sum+'0');
            
            // cout<<ans<<endl;
            

        }
        
        if(carry!=0) ans+=(carry+'0');
        
        reverse(ans.begin(),ans.end());
        
        return ans;
      
    }


int main(){

    /*
    
Input: a = "1010", b = "1011"
Output: "10101"
    
    */

    string a = "1010";
    string b = "1011";

    cout << addBinary(a, b) << endl;
}