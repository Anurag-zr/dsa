#include<bits/stdc++.h>
using namespace std;

    string minWindow(string s, string t) {
        int m = t.size();
        int n = s.size();
        
        if(n<m){
            return "";
        }
        
        unordered_map<char,int> umap;
        
        for(int i=0;i<m;i++){
            umap[t[i]]++;
        }

        // for(auto i:umap){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        int i=0;
        int minlen =0;
        int count = umap.size();
        string ans ="";
        string min;
         //"ADOBECODEBANC"
        for(int j=0;j<n;j++){      
            if(umap.find(s[j])!=umap.end()){
                umap[s[j]]--;
                if(umap[s[j]]== 0){
                    count--;
                }
            }
            
            if(count ==0){
                if((j-i+1<ans.length()) || ans.length()==0){
                    ans= s.substr(i,j-i+1);    
                }
                while(count ==0){
                    if(umap.find(s[i])!=umap.end()){
                        umap[s[i]]++;
                        if(umap[s[i]]>0){
                            count++;
                        }
                    }
                    
                    i++;
                }
                
                i--;
                umap[s[i]]--;
                count--;
                
                if(count ==0){

               if (j - i + 1 < ans.length())
                    {
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        
        return ans;
    }



    //Test case 
    //"ADOBECODEBANC"
    //"ABC"




    int main(){
        string s = "ADOBECODEBANC";
        string t = "ABC";
        cout << minWindow(s, t) << endl;
    }