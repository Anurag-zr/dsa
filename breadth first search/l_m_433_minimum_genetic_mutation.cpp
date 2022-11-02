#include<bits/stdc++.h>
using namespace std;


    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(),bank.end());
        
        if(dict.find(end)==dict.end()) return -1;
        int mut =0;
        
        char geneChoice[] = {'A','C','G','T'};
        queue<string> q;
        q.push(start);
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                string word = q.front();
                q.pop();
                
                if(end == word) return mut;
                
                dict.erase(word);
                
                for(int i=0;i<word.size();i++){
                    char c = word[i];
                    for(auto gene:geneChoice){
                        word[i] = gene;
                        if(dict.find(word)!=dict.end())
                            cout << word << endl;
                            q.push(word);
                    }
                    
                    word[i]=c;
                }
                
            }
            
            mut++;
        }
        
        
        
        return -1;
    }

    int main(){
        string start = "AACCGGTT";
        string end = "GGTTGGTT";

        vector<string> bank = {
            "AACTGGTT", "AGCTGGTT", "GGCTGGTT", "GGTTGGTT", "TACCGGTT", "TTCCGGTT"};

        cout << minMutation(start, end, bank) << endl;
    }