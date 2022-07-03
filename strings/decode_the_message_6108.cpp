#include<bits/stdc++.h>
using namespace std;

    string decodeMessage(string key, string message) {
        unordered_map<char, char> umap;
        int count = 0;
        string ans;

        for (int i = 0;i<key.length();i++) {
            if(count == 26)
                break;

            if(key[i]==' '){
                continue;
            }    
            
            if(umap.find(key[i])!=umap.end()) {
                continue;
            }
            else{

                umap[key[i]] = (char)('a' + count);
                count++;
            }
        }

        for (int i = 0;i< message.length();i++) {
            if(message[i]==' '){
                ans+=message[i];
            }
                ans = ans + umap[message[i]];
            
        }

            // cout << (char)('a'+count) << endl;

            return ans;
    }

int main(){

    string key = "eljuxhpwnyrdgtqkviszcfmabo";
    string message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";

    cout << decodeMessage(key, message);
}