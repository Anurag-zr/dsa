#include<bits/stdc++.h>
using namespace std;

    string countAndSay(int n) {
        if(n==1) return "1";
        
        string toCount = countAndSay(n-1);
        
        string say="";
        for(int i=0;i<toCount.length();i++){
          int j=i;
            while(j<toCount.length() && toCount[j]==toCount[i]){
                j++;
            }
            j--;
            say+=to_string(j-i+1)+toCount[i];
            i=j;
        }      
        
        return say;
    }

int main(){
    int n = 15;
    cout << countAndSay(n) << endl;
}