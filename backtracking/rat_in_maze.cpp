#include <bits/stdc++.h>
using namespace std;

void findPath(int i,int j,vector<vector<int>> &m,int n,string moves,vector<string> &ans,vector<vector<int>> &vis){

    if(i==n-1 && j==n-1){
        ans.push_back(moves);
        return;
    }

    //Down
    if(i+1<n  && !vis[i+1][j] && m[i+1][j]==1){
        vis[i][j] = 1;
        findPath(i + 1, j, m, n, moves+'D', ans, vis);
        vis[i][j] = 0;
    }
    
    //Left
    if(j-1>=0  && !vis[i][j-1] && m[i][j-1]==1){
        vis[i][j] = 1;
        findPath(i, j-1, m, n, moves+'L', ans, vis);
        vis[i][j] = 0;
    }

    //Right
    if(j+1<n  && !vis[i][j+1] && m[i][j+1]==1){
        vis[i][j] = 1;
        findPath(i, j+1, m, n, moves+'R', ans, vis);
        vis[i][j] = 0;
    }

    //up
    if(i-1>=0  && !vis[i-1][j] && m[i-1][j]==1){
        vis[i][j] = 1;
        findPath(i-1, j, m, n, moves+'U', ans, vis);
        vis[i][j] = 0;
    }
}

int main(){
    vector<vector<int>> m ={{0,0,0,0},
                            {1,1,0,1},
                            {1,1,0,0},
                            {0,1,1,1}};

    int n = m.size();
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<string> ans;

    if(m[0][0] ==1) findPath(0, 0, m, n, "", ans, vis);

    for(auto it:ans){
        cout << it << " " << endl;
    }

    return 0;	
}