// Battleships in a Board

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0; 
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) { 
                if (board[i][j] == 'X' && 
                    (i == 0 || board[i - 1][j] != 'X') && 
                    (j == 0 || board[i][j - 1] != 'X')) { 
                    count++;
                }
            }
        }
        
        return count; 
    }
};

/*
 * Definition:
 * The problem involves counting the number of distinct battleships on a 2D board. 
 * Each battleship occupies contiguous cells either horizontally or vertically.
 *
 * Approach:
 * - Iterate through each cell in the given 2D vector (board).
 * - For each cell that contains 'X', check if it is the topmost or leftmost part of a battleship.
 * - If it is, increment the count.
 *
 * Complexity:
 * - Time Complexity: O(m * n), where m is the number of rows and n is the number of columns 
 *   in the board. We check each cell once.
 * - Space Complexity: O(1), as we use a constant amount of extra space for counting.
 */
