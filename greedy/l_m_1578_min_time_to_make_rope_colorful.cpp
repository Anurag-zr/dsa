#include<bits/stdc++.h>
using namespace std;



    int minCost(string colors,vector<int> &neededTime){
        if(colors.length()==0 || colors.length()==1) return 0;
        
        int prev =0;
        int cur=1;
        
        int minTime =0;
        while(prev<colors.length() && cur<colors.length() ){
            if(colors[prev]==colors[cur]){
                if(neededTime[prev]<=neededTime[cur]){
                    minTime+=neededTime[prev];
                    prev=cur;
                    cur=cur+1;
                }
                else{
                    minTime+=neededTime[cur];
                    cur=cur+1;
                }
            }
            else{
                prev=cur;
                cur=cur+1;
            }
             
           
        }
        
        return minTime;
    }


int main(){
    vector<int> timeNeeded = {1, 2, 5, 1, 4, 6,5};
    cout << minCost("aaaaaaa",timeNeeded);
}