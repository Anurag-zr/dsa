#include <bits/stdc++.h>
using namespace std;


int maxScore(vector<int>& cardPoints, int k) {
     vector<int> csum(cardPoints.size(),0);
        int tsum=0;
        for(int i=0;i<cardPoints.size();i++){
            tsum+=cardPoints[i];
            csum[i] = tsum;
        }

        // for(auto i:csum){
        //     cout << i << endl;
        // }
        
        int i=0;
        int window_size = cardPoints.size() - k;
        int ans =0;int score=0;
        for(int j=0;j<cardPoints.size();j++){
            
            if(j-i+1==window_size){  //window size == k+1
                if(i==0){
                    ans = csum[j];
                    // cout << "ans:" << ans <<" "<<j<<endl;
                }
                else{
                    ans = csum[j]-csum[i-1];
                }
                
                score = max(score,tsum-ans);
                i++;
            }
        }
        
        
    return score;
}


//  less optimal but accepted leetcode 1423.

    // int maxScore(vector<int>& cardPoints, int k) {
                
    //     unordered_map<int,int> um;
        
    //     int i=0;
    //     int window_size = cardPoints.size() - k;
    //     int ans =0;int score=INT_MAX;int sum =0;
        
    //     for(int j=0;j<cardPoints.size();j++){
    //         sum+=cardPoints[j];
    //         um[j]=sum;
            
    //         if(j-i+1==window_size){
    //             if(i==0){
    //                 ans = um[j];
    //                 cout << "ans:" << ans << " " << j << endl;
    //             }
    //             else{
    //                 ans = um[j]-um[i-1];
    //             }
                
    //             score = min(score,ans);
    //             i++;
    //         }
    //     }

    //     if(k==cardPoints.size()){
    //         return sum;
    //     }
        
    //     return sum -score;
    // }

int main(){
    //[9,7,7,9,7,7,9]
   vector<int> cardPoints = {9,7,7,9,7,7,9};
//    vector<int> cardPoints = {1,2,3,4,5,6,1};
   int k = 7;
   cout << maxScore(cardPoints, k) << endl;
}