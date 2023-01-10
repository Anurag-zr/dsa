#include<bits/stdc++.h>
using namespace std;

	void floyd_warshall(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1) matrix[i][j]=1e9;
	            if(i==j) matrix[i][j]=0;
	        }
	    }
	    
	    
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    
	    
	     for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9) matrix[i][j]=-1;
	
	        }
	    }
	    
	    
	}


int main(){
    /* Initialize
    

Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}

Output: {{0,1,7},{1,0,6},{-1,-1,0}}

    
    */

    vector<vector<int>> matrix = {{0,1,43},{1,0,6},{-1,-1,0}};

    floyd_warshall(matrix);

    for(auto it: matrix){
        for(auto i: it){
                cout << i << " ";
        }
        cout << endl;
    }
}