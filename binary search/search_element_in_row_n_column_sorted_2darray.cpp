#include<bits/stdc++.h>
using namespace std;

int matSearch (int N, int M,vector<vector<int>> arr, int x)
{
    int i=0;
    int j=M-1;
    
    if(N==0 || M==0){
        return 0;
    }
    
    while(i>=0 && i<N && j>=0 && j<M){
        if(arr[i][j]==x){
            return 1;
        }
        else if(x<arr[i][j]){
            j--;
        }
        else if(x>arr[i][j]){
            i++;
        }
    }
    
    return 0;
}


int main(){
    int n = 5;
    int m = 4;

    vector<vector<int>> arr = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 47}, {32, 33, 39, 50}, {34, 35, 40, 55}};
    int key = 29;

    cout << matSearch(n, m, arr, key) << endl;
}