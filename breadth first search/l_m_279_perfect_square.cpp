#include<bits/stdc++.h>
using namespace std;

    int numSquares(int n) {
         vector<int> perfectSq;
         vector<int> cntPerfectSq(n+1,0);  //cnt[i]=least no. of perfect sq which sum to i
         cntPerfectSq[0]=0;   
        
        
        queue<int> searchQ;
        for(int i=1;i*i<=n;i++){
            perfectSq.push_back(i*i);
            cntPerfectSq[i*i]=1;
            searchQ.push(i*i);
        }
        
        
        if(perfectSq.back()==n) return 1;
        
        int currCntPerfectSq =1;
        
        while(!searchQ.empty()){
            int searchQSize = searchQ.size();
            currCntPerfectSq++;
            
            for(int i=0;i<searchQSize;i++){
                int tmp = searchQ.front();
                searchQ.pop();
                
                for(auto &j:perfectSq){
                    
                    if(tmp+j==n) return currCntPerfectSq;
                    else if(tmp+j<n  && (cntPerfectSq[tmp+j]==0)){
                        cntPerfectSq[tmp+j]=currCntPerfectSq;
                        searchQ.push(tmp+j);
                    }
                    else if(tmp+j>n) break;
                }
            }
        }
        
        
        return 0;

    }

int main(){
    cout << numSquares(12) << endl;
    cout << numSquares(13) << endl;
    cout << numSquares(120) << endl;
}