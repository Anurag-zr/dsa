#include<bits/stdc++.h>
using namespace std;

    bool dfs(int i,int j,int wordptr,vector<vector<char>> &board,vector<vector<int>> &vis,string &word,vector<int> &dx,vector<int> &dy){
        
        vis[i][j]=1;
        if(wordptr==word.size()) return true;
        
        for(int k=0;k<4;k++){
            int nr = i+dx[k];
            int nc = j+dy[k];
            
            if(nr<0 || nr>=board.size() || nc<0 || nc>=board[0].size()) continue;
            
            if(!vis[nr][nc] && board[nr][nc]==word[wordptr])
                if(dfs(nr,nc,wordptr+1,board,vis,word,dx,dy)) return true;
            
            
        }
        
        vis[i][j]=0;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m= board[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        int wordptr =0;
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]==word[wordptr] )
                    if(dfs(i,j,wordptr+1,board,vis,word,dx,dy)==true) return true;
            }
        }
        
        
        return false;
    }

int main(){

  /*  Input: board = [["A","B","C","E"],
    ["S","F","C","S"],
    ["A","D","E","E"]]
    , word = "ABCCED"


  */

vector<vector<char>> board ={{'A','B','C','E'},
{'S','F','C','S'},
{'A','D','E','E'}};

string word = "ABCCED";

cout << exist(board, word) << endl;
}