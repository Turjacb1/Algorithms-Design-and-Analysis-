#include <iostream>
#include <vector>
using namespace std;

#define N 4

void print(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool safe(vector<vector<int>>& board, int row, int col) {
    
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool queen(vector<vector<int>>& board, int row) {
    if (row == N) {
        print(board); 
        return true;   
    }

    for (int col = 0; col < N; col++) {
        if (safe(board, row, col)) {
            board[row][col] = 1;                    
            if (queen(board, row + 1))  
                return true;
            board[row][col] = 0; 
        }
    }

    return false;  
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));  

    cout << "5-Queens Problem:\n\n";
    if (!queen(board, 0)) {
        cout << "No solution exists.\n";
    }

    return 0;
}