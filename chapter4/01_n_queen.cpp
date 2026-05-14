#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>& board,int row, int col, int n){
    for(int i=0;i<col;i++){
        if(board[row][i]) return false;
    }

    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]) return false;
    }
    
    for(int i=row,j=col;i<n&&j>=0;i++,j--){
        if(board[i][j]) return false;
    }

    return true;
}

void printBoard(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (board[i][j] ? " Q " : " . ");
        cout << endl;
    }
    cout << endl;
}

bool solve(vector<vector<int>>& board, int col, int n){

    if(col==n){
        printBoard(board, n);
        return true;
    }

    for(int row = 0;row<n; row++){
        if(check(board, row, col, n)){
            board[row][col] = 1;
            if(solve(board, col+1, n)){
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;

}

int main(){
    int n = 8;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(board, 0, n);
}