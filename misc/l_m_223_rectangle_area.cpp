#include<bits/stdc++.h>
using namespace std;



    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int  cx1= max(ax1,bx1);  // common area first x coordinate
        int cy1 = max(ay1,by1);  // common area first y coordinate
        
        int cx2 = min (ax2,bx2);  // common area second x coordinate
        int cy2 = min(ay2,by2);  // common area second  y coordinate
        
        int commonArea =0;
        
        if(cx1<=cx2 && cy1<=cy2) commonArea = (cx2-cx1) * (cy2-cy1);
        
        int areaA = (ax2-ax1) * (ay2-ay1);
        int areaB = (bx2-bx1) * (by2-by1);
        
        
        
        return (areaB + areaA - commonArea);
    }



    int main(){
// Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
// Output: 45
int ax1 = -3;
int ay1 = 0;
int ax2 = 3;
int ay2 = 4;

int bx1 = 0;
int by1 = -1;
int bx2 = 9;
int by2 = 2;

cout << computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) << endl;
    }