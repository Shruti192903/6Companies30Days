//Stone Game VI

class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int m = a.size();
        vector<vector<int>> indices(201);
        for (int i = 0; i < m; ++i) {
            indices[a[i] + b[i]].push_back(i);
        }
        
        bool turn = true;
        int ta = 0, tb = 0;
        for (int i = 200; i >= 0; --i) {
            for (auto index: indices[i]) {
                if (turn) {
					ta += a[index];
                } else {
                    tb += b[index];
                }

                turn = !turn;    
            }
        }
        
        if (ta > tb) return 1;
        else if (ta < tb) return -1;
        return 0;
    }
};

/*
 * Definition:
 * The problem involves determining the outcome of a game between two players 
 * where they take turns picking stones. Each stone has associated points for 
 * both players, and they will always choose the stone that maximizes their score.
 *
 * Approach:
 * - Use an array to group indices of stones based on their combined point values.
 * - Iterate from the highest possible point value down to zero, alternating turns 
 *   between players and accumulating their scores based on chosen stones.
 *
 * Complexity:
 * - Time Complexity: O(m), where m is the number of stones. We process each stone once 
 *   to populate indices and then again to calculate scores.
 * - Space Complexity: O(1), as we use a fixed-size array for indices (size 201).
 */
