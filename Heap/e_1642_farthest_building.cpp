#include<bits/stdc++.h>
using namespace std;

int furthestBuilding(vector<int> &heights,int bricks,int ladders){
    priority_queue<int> pq;
    int diff = 0;
    int i;
    for (i = 0; i < heights.size() - 1;i++){
        
        diff= heights[i+1]-heights[i];

        if(diff<=0) continue;

        bricks-=diff;
        pq.push(diff);

        if(bricks<0){
            bricks += pq.top();
            pq.pop();
            ladders--;
        }

        if(ladders <0){
            break;
        }

    }

    return i;
}

int main(){
    vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
    int bricks = 5;
    int ladders = 1;

    cout<<furthestBuilding(heights,bricks,ladders)<<endl;
}