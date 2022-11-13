#include<bits/stdc++.h>
using namespace std;

    string reverseWords(string s) {
        stack<string> st;
        string str;
        stringstream ss(s);
        
        while(ss>>str){
            st.push(str);
        }
        
        string ans ="";
        
        while(!st.empty()){
            ans+= st.top()+' ';
            st.pop();
        }
        
        ans = ans.substr(0,ans.length()-1);
        
        return ans;
    }

int main(){

    cout << reverseWords("   Hello  world  ") << endl;
    cout << reverseWords("I know    about  you  ") << endl;
}