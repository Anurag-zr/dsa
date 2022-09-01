#include<bits/stdc++.h>
using namespace std;


    
    int first(vector<int> &arr,int start,int end){
        int ans=-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(arr[mid]==1){
                ans = mid;
                end = mid-1;
            }
            else if(1>arr[mid]){
                start = mid+1;
            }
            else if(1<arr[mid]){
                end = mid-1;
            }
        }
        
        return ans;
    }

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int max_1s_index =-1;
	    int index = first(arr[0],0,m-1);
	   // cout<<index<<endl;
	   
	   if(index!=-1) max_1s_index=0;
	    
	   // int no_1s = m - index;
	    
	    for(int i=1;i<n;i++){
	        if(index-1>=0 && arr[i][index-1]==1){
	            index = first(arr[i],0,index-1);
	            max_1s_index = i;
	        }
	        else if(index==-1){
	            index = first(arr[i],0,m-1);
	            if(index!=-1) max_1s_index=i;
	            
	        }
	    }
	    
	    return max_1s_index;
	}


int main(){
    vector<vector<int>> mat = {
        {0,0,0,0},
        {0,0,1,1},
        {1,1,1,1},
        {0,0,0,1}
    };

    cout << rowWithMax1s(mat, mat.size(), mat[0].size());
}