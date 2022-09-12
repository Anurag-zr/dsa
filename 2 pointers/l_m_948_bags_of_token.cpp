#include<bits/stdc++.h>
using namespace std;


    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int start = 0; int end = tokens.size()-1;
        int score=0;
        int maxi =0;
        
        while(start<=end){
            if(power>=tokens[start]){
                power-=tokens[start++];
                maxi = max(maxi,++score);
            }
            else if(score>0){
                power+=tokens[end--];
                score--;
            }
            else{
                break;
            }
        }
        
        return maxi;
    }




int main(){
    vector<int> tokens = {243, 45, 98};
    int power = 100;
    cout<<bagOfTokensScore(tokens,power);

}