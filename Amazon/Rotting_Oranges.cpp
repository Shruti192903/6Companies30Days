//Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        queue<pair<pair<int, int>, int>> q;
        int freshCount = 0;

        // Initialize the visited array and queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2;
                    q.push({{i, j}, 0}); // Push rotten orange with time 0
                } else {
                    vis[i][j] = 0; // Mark as unvisited
                }
                if (grid[i][j] == 1) freshCount++; // Count fresh oranges
            }
        }

        // Define the directions for 4-way movement
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        int time = 0;
        int rottedCount = 0;

        // Process the queue
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t); // Track the maximum time

            // Traverse in 4 directions
            for (int k = 0; k < 4; k++) {
                int newRow = row + dRow[k];
                int newCol = col + dCol[k];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && vis[newRow][newCol] == 0) {
                    q.push({{newRow, newCol}, t + 1});
                    vis[newRow][newCol] = 2; // Mark as visited (rotted)
                    rottedCount++; // Increment the count of rotted oranges
                }
            }
        }

        // Check if all fresh oranges were rotted
        if (rottedCount != freshCount) return -1;

        return time;
    }
};

/*
 * Definition:
 * Given an m x n grid representing the state of oranges, where:
 * - 0 represents an empty cell,
 * - 1 represents a fresh orange,
 * - 2 represents a rotten orange.
 * The goal is to determine the minimum number of minutes until no fresh oranges remain.
 * If it is impossible for all oranges to rot, return -1.
 *
 * Approach:
 * - Use BFS to spread the rot from rotten oranges to adjacent fresh oranges.
 * - Initialize a visited array and a queue with all rotten oranges and their initial time (0).
 * - For each rotten orange, check its four adjacent cells. If an adjacent cell contains a fresh orange,
 *   rot it (mark it as visited) and add it to the queue with an incremented time.
 * - Track the maximum time taken for all oranges to rot.
 * - After processing, check if all fresh oranges have been rotted; if not, return -1.
 *
 * Complexity:
 * - Time Complexity: O(m * n), where m is the number of rows and n is the number of columns,
 *   as we may need to visit each cell in the grid once.
 * - Space Complexity: O(m * n) for storing the queue and potentially marking visited states.
 */
