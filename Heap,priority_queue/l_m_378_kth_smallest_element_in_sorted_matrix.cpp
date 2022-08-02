#include<bits/stdc++.h>
using namespace std;

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;  //max heap
        
        int n= matrix.size();
        int m= matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k) pq.pop();
            }
        }
        
        
        return pq.top();
    }


    int main(){
        vector<vector<int>> matrix = {{1, 2, 3}, {7, 20, 34}, {9, 21, 40}};
        int k = 8;
        cout << kthSmallest(matrix, k) << endl;
    }