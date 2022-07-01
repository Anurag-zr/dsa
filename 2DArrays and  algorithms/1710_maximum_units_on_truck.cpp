#include<bits/stdc++.h>
using namespace std;

    bool comp(vector<int>& a,vector<int>& b){
        if(a[1]==b[1]) return a[0]>b[0];
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
       sort(boxTypes.begin(),boxTypes.end(),comp);
       int n = boxTypes.size();
        int i=0;
        int mxunit =0;
        while(truckSize != 0 && i<n){
            if(truckSize>=boxTypes[i][0]){
                mxunit+= (boxTypes[i][0]*boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            }
            else if(truckSize< boxTypes[i][0]){
                mxunit+= truckSize * boxTypes[i][1];
                truckSize = 0;
            }

            cout<<"truckSize: " << truckSize <<" mxunit: "<<mxunit<<endl;

            i++;
        }
            
            return mxunit;
    }


int main(){
  
//   [[1,3],[2,2],[3,1]]  4

vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
int truckSize = 4;

cout << maximumUnits(boxTypes, truckSize);


}