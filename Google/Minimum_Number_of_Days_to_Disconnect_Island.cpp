//Minimum Number of Days to Disconnect Island

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        auto count_islands = [&]() -> int {
            vector<vector<int>> seen(grid.size(), vector<int>(grid[0].size(), 0));
            int islands = 0;
            
            function<void(int, int)> dfs = [&](int r, int c) {
                seen[r][c] = 1;
                for (auto [dr, dc] : {pair{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1 && !seen[nr][nc]) {
                        dfs(nr, nc);
                    }
                }
            };
            
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 1 && !seen[i][j]) {
                        islands++;
                        dfs(i, j);
                    }
                }
            }
            return islands;
        };
        
        if (count_islands() != 1) return 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (count_islands() != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};

/*
 * Definition:
 * The problem involves determining how many days are required to ensure that all 
 * land cells in a given grid are connected. A cell can be removed each day.
 *
 * Approach:
 * - Use Depth-First Search (DFS) to count the number of islands in the grid.
 * - First check if there is already one island. If not, return 0.
 * - For each land cell, temporarily remove it and check if it disconnects 
 *   the remaining land cells. If it does, return 1.
 * - If no single removal disconnects the land cells, return 2.
 *
 * Complexity:
 * - Time Complexity: O(N*M), where N is the number of rows and M is the number 
 *   of columns in the grid. Each cell is visited multiple times during DFS.
 * - Space Complexity: O(N*M), used for the seen matrix in DFS.
 */
