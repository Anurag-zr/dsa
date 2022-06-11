#include<bits/stdc++.h>
using namespace std;

bool isPossible(int row,int col,vector<string> board,int n){
        int duprow = row;
        int dupcol =col;
        
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        while(row>=0){
            if(board[row][col]=='Q') return false;
            row-- ;
        }
        
        row = duprow;
        col = dupcol;
        
        while(row>=0 && col<n){
            if(board[row][col] == 'Q') return false;
            col++;
            row--;
        }
        
        return true;
}

void solveNQueen(int row,vector<string> &board,int &ans,int n){

    if(row == n){
        ans++;
        return;
    }

    for (int col = 0; col < n;col++){
        if(isPossible(row,col,board,n)){
            board[row][col] = 'Q';
            solveNQueen(row + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

int main(){

    int n = 8;

    int ans=0;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n;i++){
        board[i] = s;
    }

        solveNQueen(0, board, ans, n);

        cout << "n: " << n << endl;
        cout << "ans: " << ans << endl;
}