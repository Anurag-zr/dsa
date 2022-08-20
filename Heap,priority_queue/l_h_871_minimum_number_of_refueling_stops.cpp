#include<bits/stdc++.h>
using namespace std;

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      if(startFuel>=target) return 0;
        priority_queue<int> pq;
        
        int i=0,maxDistance=startFuel,n = stations.size();
        int stops =0;
        
        while(maxDistance<target){
            while(i<n && stations[i][0]<=maxDistance){
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty()) return -1;
            maxDistance+= pq.top();
            pq.pop();
            stops++;
        }
        
        return stops;
    }


int main(){

    // target = 100, startFuel = 10,
    //  stations = [[10,60],[20,30],[30,30],[60,40]]

    int target = 100;
    int startFuel = 10;
    vector<vector<int>> stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    cout<<minRefuelStops(target,startFuel,stations)<<endl;
}