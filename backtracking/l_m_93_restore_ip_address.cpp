#include<bits/stdc++.h>
using namespace std;

    void restoreIpDfs(int ind,int cnt,string restoredIp,string &s,vector<string> &ans){
        if(cnt>4) return;
        if(s.length()-ind > 3*(4-cnt)) return;
        if(cnt==4 && ind == s.length()){
            ans.push_back(restoredIp);
            return;
        }
        
    
        
        for(int i=1;i<=3;i++){
            if(ind+i> s.length()) break;
            string part = s.substr(ind,i);
            
            if(part[0]=='0' && part.length()!=1) break;
            if(stoi(part)>=256) break;
            
            restoreIpDfs(ind+i,cnt+1,restoredIp+part+(cnt==3?"":"."),s,ans);
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        if(s.length()>12) return {};
        
        string restoredIp="";
        vector<string> ans;
        
        restoreIpDfs(0,0,restoredIp,s,ans);
        
        return ans;
    }

int main(){
    string ip = "012201";
    vector<string> posIp = restoreIpAddresses(ip);

    for(auto ip: posIp){
            cout << ip << endl;
    }
}