#include<bits/stdc++.h>
using namespace std;

    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<int> tz;
        
        for(int i=0;i<n;i++){
            int cntZero =0;
            for(int j=n-1;j>=0 && !grid[i][j];j--) cntZero++;
            tz.push_back(cntZero);
        }
        
        int ans =0;
        for(int i=0;i<n;i++){
            
            int k =i;
            int reqZero = n-1-i;
            while(k<n && tz[k]<reqZero)k++;
            if(k==n) return -1; // reqZero not found
            
            ans+= k-i; // no. of swap needed
            
            while(k>i){
                swap(tz[k],tz[k-1]);
                k--;
            }
        }
        
        // for(auto e: tz) cout<<e<<endl;
        
      return ans;
    }


int main(){
    /* Initial
    
    Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3
    */

    vector<vector<int>> grid = {
        {0, 0, 1}, {1, 1, 0}, {1, 0, 0}};

    cout << minSwaps(grid) << endl;
}