#include <bits/stdc++.h>
using namespace std;
 
 bool isPalindrome(int i,char str[] , int n){
     if(i>=n/2){
         return true;
     }

     if(str[i] != str[n-i-1]){
         return false;
     }

     return isPalindrome(i + 1, str, n);
 }

int main(){

    char str[] = "madsm";
    bool ans = isPalindrome(0, str, 6);

    if(ans)
        cout << str << " is palindrome" << endl;
     else   cout << str <<" is not a palindrome" << endl;
}