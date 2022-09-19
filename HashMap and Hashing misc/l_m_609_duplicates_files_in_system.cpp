#include<bits/stdc++.h>
using namespace std;

    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> files;
        vector<vector<string>> ans;
        
        for(auto path:paths){
            stringstream ss(path);  // or ss<<path;
            string root="";
            
            getline(ss,root,' ');
            
            string str="";
            
            while(getline(ss,str,' ')){
                string fileName = root+'/'+str.substr(0,str.find('('));
                string fileContent = str.substr(str.find('(')+1,str.find(')')-str.find('(')-1);
                
                
                files[fileContent].push_back(fileName);
            }
            
        }
        
        
        for(auto file:files){
            if(file.second.size()>1){
                ans.push_back(file.second);
            }
        }
            
        return ans;
    }




int main(){
    /* 
Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
    */


   vector<string> paths ={
    "root/a 1.txt(abcd) 2.txt(efgh)",
    "root/c 3.txt(abcd)",
    "root/c/d 4.txt(efgh)",
    "root 4.txt(efgh)"
   };

   vector<vector<string>> ans = findDuplicate(paths);

   for(auto duplicates: ans){
    for(auto filePath:duplicates){
        cout << filePath << " ";
    }
    cout << endl;
   }



}