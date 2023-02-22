#include<bits/stdc++.h>
using namespace std;

/*

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given
, so using a ship of capacity 14 and splitting the packages
 into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

 */

    int shipWithinDays(vector<int>& weights, int days) {
        int sum =0;
        int left=0;
        for(auto ele: weights){
            left = max(left,ele);
            sum+=ele;
        }
        
        int right = sum;
        
        
        while(left<right){
            
            int mid = left + (right - left)/2;
            int cap = mid;
            int curW=0;
            int rDays=1;
            
            for(auto ele: weights){
                if(ele>cap){
                    rDays = 1e9;
                    break;
                }
                
                if(curW+ele<=cap){
                    curW+=ele;
                }
                else{
                    curW=ele;
                    rDays++;
                }
            }
            
            // cout<<cap<<" "<<rDays<<endl;
            
            if(rDays>days) left=mid+1;
            else right = mid;
        }
        
        
        
        return left;
    }


int main(){
    vector<int> weights ={1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout << shipWithinDays(weights, days) << endl;
}