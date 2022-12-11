#include<bits/stdc++.h>
using namespace std;


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level =0;
        
        vector<vector<string>> ans;
        
        
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            
            //erase all words that has been used in previous level to transform
            if(vec.size()>level){
                level++;
                for(auto it: usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            
            
            string word = vec.back();
            
            
            if(word==endWord){
                //first time we reached end
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        
                        //mark as visited on level
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=original;
            }
            
            
            
        }
        
        return ans;
    }

int main(){
    /*
    
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
    
    */


   string beginWord ="hit";
   string endWord = "cog";
   vector<string> wordList = {"hot", "dot", "dog", "log", "lot", "cog"};

   vector<vector<string>> ans= findLadders(beginWord, endWord,wordList);

   for(auto it:ans){
    for(auto i:it){
        cout << i << " ";
    }
    cout << endl;
   }
}