//Valid Sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        //For each cell
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue; //Skipping empty cells
                }

                //Calculating box index
                char value = board[r][c];
                int boxIndex = (r / 3) * 3 + (c / 3);

                if (rows[r].count(value) || cols[c].count(value) || boxes[boxIndex].count(value)) {
                    return false; //Invalid
                }

                rows[r].insert(value);
                cols[c].insert(value);
                boxes[boxIndex].insert(value);
            }
        }

        return true;        
    }
};


/*
 * Definition:
 * Given a 9x9 Sudoku board, determine if it is valid. 
 * A valid Sudoku board must satisfy the following conditions:
 * 1. Each row must contain the digits 1-9 without repetition.
 * 2. Each column must contain the digits 1-9 without repetition.
 * 3. Each of the nine 3x3 sub-boxes must contain the digits 1-9 without repetition.
 *
 * Approach:
 * - Use three arrays of unordered sets to track seen digits for rows, columns, and boxes.
 * - Iterate through each cell in the 9x9 board.
 * - For each non-empty cell, check if the digit already exists in its corresponding row, column, or box.
 * - If a digit is found in any of these sets, return false (the board is invalid).
 * - If no duplicates are found after checking all cells, return true (the board is valid).
 *
 * Complexity:
 * - Time Complexity: O(1) since we always check a fixed number of cells (81).
 * - Space Complexity: O(1) as well, since the space used for sets is constant (at most 27 sets).
 */
