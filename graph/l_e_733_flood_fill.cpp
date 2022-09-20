#include<bits/stdc++.h>
using namespace std;

    void dfs(int r,int c,int &color,int &intColor,vector<vector<int>> &image,vector<vector<bool>> &vis){
        if(r<0 || r>=image.size() || c<0 || c>=image[0].size())  return;
        
        if(!vis[r][c] && image[r][c]==intColor){
            image[r][c]=color;
            vis[r][c]=true;
        
        
        dfs(r-1,c,color,intColor,image,vis); //up
        dfs(r,c+1,color,intColor,image,vis); //right
        dfs(r+1,c,color,intColor,image,vis); //down
        dfs(r,c-1,color,intColor,image,vis); //left
            
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size();
        int m= image[0].size();
        
        int intColor = image[sr][sc];
        
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        
        dfs(sr,sc,color,intColor,image,vis);
        
        return image;
    }


int main(){
    // Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    int sr = 1;
    int sc = 1;
    int color = 2;

    floodFill(image, sr, sc, color);

    for(auto it:image){
        for(auto i:it){
            cout << i << " ";
        }
        cout << endl;
    }
}