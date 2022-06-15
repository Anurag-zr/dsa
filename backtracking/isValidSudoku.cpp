#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<vector<char>> &board){

 for(int i=0;i<board.size();i++){
     for (int j = 0; j < board[i].size();j++){
        if(board[i][j] != '.'){
            
                if(isvalid(board,i,j,board[i][j]) == false){
                    cout << "false" << endl;
                    cout << i << " " << j << " " << board[i][j] << endl;
                    return false;
                }
        }
     }
 }

 return true;
}

bool isvalid(vector<vector<char>> &board,int row,int col,char c){
    for (int i = 0; i < 9;i++){
        if(i == row) continue;
        if(i== col) continue;
        if((3*(col/3) + i%3) == col) continue;
        if((3*(row/3) + i/3) == row) continue;
        if(board[i][col] == c){
            cout << "because of row"<<"i:"<<i<<"col:"<<col<<endl;
            return false;
        }

        if(board[row][i]==c){
            cout << "because of col";
            return false;
        }

        if(board[3*(row/3) + i/3][3*(col/3) + i%3]==c){
            cout << "because of grid"<<" "<<"i:"<<3*(row/3) + i/3<<"j: "<<3*(col/3) + i%3<<endl;
            return false;
        }

        
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};

int main(){
    Solution obj;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << obj.isValidSudoku(board) << endl;
}

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

not solvable why??

*/