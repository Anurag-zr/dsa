#include<bits/stdc++.h>
using namespace std;

// bool isPossible(int row,int col,vector<string> board,int n){
//         int duprow = row;
//         int dupcol =col;
        
//         while(row>=0 && col>=0){
//             if(board[row][col]=='Q') return false;
//             row--;
//             col--;
//         }
        
//         row = duprow;
//         col = dupcol;
//         while(row>=0){
//             if(board[row][col]=='Q') return false;
//             row-- ;
//         }
        
//         row = duprow;
//         col = dupcol;
        
//         while(row>=0 && col<n){
//             if(board[row][col] == 'Q') return false;
//             col++;
//             row--;
//         }
        
//         return true;
// }

void solveNQueen(int row,vector<string> &board,int &ans,int n,
                 vector<int> &uppercol,vector<int> &NEDiagonal,vector<int> &NWDiagonal){

    if(row == n){
        ans++;
        return;
    }

     for(int col =0;col<n;col++){
        if(uppercol[col]==0 && NEDiagonal[row+col] == 0
            && NWDiagonal[n-1+col-row]==0){
                board[row][col]='Q';
                uppercol[col]=1;
                NEDiagonal[row+col] =1;
                NWDiagonal[n-1+col-row] =1;
                solveNQueen(row+1,board,ans,n,uppercol,NEDiagonal,NWDiagonal);
                board[row][col] ='.';
                uppercol[col]=0;
                NEDiagonal[row+col]=0;
                NWDiagonal[n-1+col-row]=0;
            }
        }
}

int main(){

    int n = 4;

    int ans=0;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n;i++){
        board[i] = s;
    }

    vector<int> uppercol(n,0),NEDiagonal(2*n-1,0),NWDiagonal(2*n-1,0);

        solveNQueen(0, board, ans, n,uppercol,NEDiagonal,NWDiagonal);

        cout << "n: " << n << endl;
        cout << "ans: " << ans << endl;
}