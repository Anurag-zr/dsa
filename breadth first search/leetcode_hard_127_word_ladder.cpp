#include<bits/stdc++.h>
using namespace std;


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord) == dict.end()) return 0;

        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = true;
        int ladder =1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                string word = q.front();
                q.pop();
                
                if(word == endWord) return ladder;

                
                for(int j=0;j<word.size();j++){
                    char c = word[j];
                    for(int k='a';k<='z';k++){
                        word[j]= (char) k;
                        if(dict.find(word) != dict.end()  && !visited[word]){
                            q.push(word);
                        }
                    }
                    
                    word[j] = c;
                }
            }
            
            ladder++;
        }
        
        return 0;
    }


int main(){
// beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
string beginWord = "hit", endWord = "cog";
vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

cout<<ladderLength(beginWord, endWord,wordList)<<endl;

}