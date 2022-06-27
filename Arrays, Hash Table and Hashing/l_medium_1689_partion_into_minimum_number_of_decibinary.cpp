#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "234569807214569";
    char maxi = '0';

    for (int i = 0;i<s.length();i++){
        maxi = max(maxi, s[i]);

        if(maxi == '9')
            break;
    }

    cout << maxi - '0' << endl;
    
}