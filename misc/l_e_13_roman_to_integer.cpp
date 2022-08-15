#include<bits/stdc++.h>
using namespace std;

    int romanToInt(string s) {
        unordered_map<char,int> romIntTransition={
                                                    {'I',1},
                                                    {'V',5},
                                                    {'X',10},
                                                    {'L',50},
                                                    {'C',100},
                                                    {'D',500},
                                                    {'M',1000}
                                                };
        
        int sum =0;
        
        for(int i = 0;i<s.length()-1;i++){
            if(romIntTransition[s[i]]<romIntTransition[s[i+1]]){
                sum-=romIntTransition[s[i]];
            }
            else{
                sum+=romIntTransition[s[i]];
            }
        }
        
        
        return sum+=romIntTransition[s[s.length()-1]];
    }


int main(){
    string roman = "CXVIII";
    cout << romanToInt(roman) << endl;
}