#include <iostream>
using namespace std;

#define N 8

bool isSafe(int board[N][N], int row, int col) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

bool solveNQueens(int board[N][N], int row) {
    if (row >= N) return true;  // All queens placed

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;          // Place queen
            if (solveNQueens(board, row + 1))
                return true;               // Continue to next row
            board[row][col] = 0;           // Backtrack
        }
    }
    return false;
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int board[N][N] = {0};

    // First queen is placed, e.g. at row 0, column 0
    board[0][0] = 1;

    if (solveNQueens(board, 1))
        printBoard(board);
    else
        cout << "No solution exists";

    return 0;
}
