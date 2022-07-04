#include<bits/stdc++.h>
using namespace std;

  int totalFruit(vector<int>& fruits) {
        if(fruits.size() <=2){
            return fruits.size();
        }
        
        int maxlen =0;
        unordered_map<int,int> umap;
        // int uniquefruits =0;
        
        int i=0;
        for(int j=0;j<fruits.size();j++){
            umap[fruits[j]]++;
            int size = umap.size();
            if(size <= 2){
                maxlen = max(maxlen,j-i+1);
            }
            
            else if(size>2){
                while(size>2){
                    umap[fruits[i]]--;
                    if(umap[fruits[i]]==0){
                        umap.erase(fruits[i]);
                        size--;
                    }
                    i++;
                }
                
                if(size == 2){
                    maxlen = max(maxlen,j-i+1);
                }
            }
        }
        
        return maxlen;
    }


int main(){
    vector<int> fruits = {1, 2, 3, 2, 2, 2};
    cout << totalFruit(fruits) << endl;
}