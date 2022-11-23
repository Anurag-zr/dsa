#include <bits/stdc++.h>
using namespace std;

bool isvalid(vector<vector<char>> &board,int row,int col,char c){
    for (int i = 0; i < 9;i++){
        // if(i == row) continue;
        // if(i== col) continue;
        // if((3*(col/3) + i%3) == col) continue;
        // if((3*(row/3) + i/3) == row) continue;
        if(board[i][col]== c){
            return false;
        }

        if(board[row][i]==c){
            return false;
        }

        if(board[3*(row/3) + i/3][3*(col/3) + i%3]==c){
            return false;
        }

        
    }
    return true;
}

    bool solve(vector<vector<char>> &board){

 for(int i=0;i<board.size();i++){
     for (int j = 0; j < board[i].size();j++){
        if(board[i][j] != '.'){
                char c= board[i][j];
                board[i][j]='.';
                if(!isvalid(board,i,j,c)) return false;
                board[i][j]=c;
        }
     }
 }

 return true;
}

    
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }


int main(){

    /*----------------------------------------------------------------

[
[".",".","4",".",".",".","6","3","."],
[".",".",".",".",".",".",".",".","."],
["5",".",".",".",".",".",".","9","."],
[".",".",".","5","6",".",".",".","."],
["4",".","3",".",".",".",".",".","1"],
[".",".",".","7",".",".",".",".","."],
[".",".",".","5",".",".",".",".","."],
[".",".",".",".",".",".",".",".","."],
[".",".",".",".",".",".",".",".","."],
]


*/

    vector<vector<char>> board = {
        { '.', '.', '4', '.', '.', '.', '6', '3', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '5', '.', '.', '.', '.', '.', '.', '9', '.' },
        { '.', '.', '.', '5', '6', '.', '.', '.', '.' },
        { '4', '.', '3', '.', '.', '.', '.', '.', '1' },
        { '.', '.', '.', '7', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '5', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    };

    cout << isValidSudoku(board) << endl;
}