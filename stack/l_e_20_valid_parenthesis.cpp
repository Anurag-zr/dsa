#include<bits/stdc++.h>
using namespace std;


    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                stk.push(s[i]);
            }
            
            else{
                char bracket;
                if(!stk.empty()){ bracket = stk.top(); stk.pop();}
                else return false;
                
                if(s[i]==')' && bracket=='(') continue;
                else if(s[i]==']' && bracket=='[') continue;
                else if(s[i]=='}' && bracket=='{') continue;
                else return false;
            }
        }
        
        if(stk.empty())
        return true;
        
        return false;
    }


int main(){

    cout << isValid("()({[]})") << endl;
    cout << isValid("()({[]}") << endl;
    cout << isValid("(") << endl;
    cout << isValid("([]{})") << endl;
}