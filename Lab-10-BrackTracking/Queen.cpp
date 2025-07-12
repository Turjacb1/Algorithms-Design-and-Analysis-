#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>>& board, intN) {
    for (int i =0;i <N;i++) {
        for (int j =0; j <N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool safe(vector<vector<int>>& board,int row,int col,int N) {
    
    for (int i=0; i <row;i++)
        if (board[i][col])
            return false;

    
    for (int i=row,j=col; i >=0 && j >=0; i--,j--)
        if (board[i][j])
            return false;

    
    for (int i=row,j =col;i >=0 && j <N;i--,j++)
        if (board[i][j])
            return false;

    return true;
}


bool queen(vector<vector<int>>& board,int row,int N) {
    if (row == N) {
        print(board, N);
        return true;
    }

    for (int col =0;col<N;col++) {
        if (safe(board, row, col, N)) {
            board[row][col] = 1;
            if (queen(board, row + 1, N))
                return true;
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int N;
    cout << " board size  ";
    cin >> N;
    if (N <= 0) {
        cout << "invalid input.\n";
        return 1;
    }
    vector<vector<int>> board(N, vector<int>(N, 0));

    cout <<N<<"-queens problem:\n\n";
    if (!queen(board, 0, N)) {
        cout << "no solution.\n";
    }

    return 0;
}