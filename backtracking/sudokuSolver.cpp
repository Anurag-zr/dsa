#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<vector<char>>&, int, int, char);

bool solve(vector<vector<char>> &board){

 for(int i=0;i<board.size();i++){
     for (int j = 0; j < board[0].size();j++){
        if(board[i][j] == '.'){
            for (char c = '1'; c <= '9';c++){
                if(isvalid(board,i,j,c) == true){
                    board[i][j] = c;

                    if(solve(board) == true)
                        return true;
                    else
                        board[i][j] = '.';
                }
            }
            return false;
        }
     }
 }

 return true;
}

bool isvalid(vector<vector<char>> &board,int row,int col,char c){
    for (int i = 0; i < 9;i++){
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

int main(){
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};


    for(auto it: board){
        for(auto it1: it){
            cout << it1 << " ";
        }
        cout << endl;
    }

    solve(board);

    cout << "-----------------ans---------------------" << endl;

    for(auto it: board){
        for(auto it1: it){
            cout << it1 << " ";
        }
        cout << endl;
    }

}