#include <vector>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }

private:
    // Main recursive backtracking function
    bool solve(std::vector<std::vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                // Find an empty cell
                if (board[row][col] == '.') {
                    // Try placing numbers '1' through '9'
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num; // Place the number

                            // Recurse to solve the rest of the board
                            if (solve(board)) {
                                return true; // Found a solution!
                            }

                            // If recursion failed, backtrack
                            board[row][col] = '.'; // Un-place the number
                        }
                    }
                    // If no number from 1-9 works here, this path is wrong
                    return false;
                }
            }
        }
        // If all cells are filled, we've found a solution
        return true;
    }

    // Helper function to check if a number placement is valid
    bool isValid(const std::vector<std::vector<char>>& board, int row, int col, char num) {
        // Check the current row and column
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == num) return false; // Check row
            if (board[i][col] == num) return false; // Check column
        }

        // Check the 3x3 sub-grid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[startRow + i][startCol + j] == num) {
                    return false;
                }
            }
        }

        return true; // The placement is valid
    }
};
