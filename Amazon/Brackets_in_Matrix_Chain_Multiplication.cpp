//Brackets in Matrix Chain Multiplication

class Solution{
public:
string matrixChainOrder(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0)); // DP table for costs
    vector<vector<string>> bracket(n, vector<string>(n)); // Table for parenthesization

    // Initialize matrix names (A, B, C, ...)
    char matrixName = 'A';
    for (int i = 1; i < n; ++i) {
        bracket[i][i] = string(1, matrixName++); // Assign names to single matrices
    }

    // Calculate minimum cost and optimal parenthesization
    for (int len = 2; len < n; ++len) { // Length of chain
        for (int i = 1; i <= n - len; ++i) { // Starting index
            int j = i + len - 1; // Ending index
            dp[i][j] = INT_MAX; // Initialize with a large value

            for (int k = i; k < j; ++k) { // Possible split points
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (cost < dp[i][j]) { // Update if we found a cheaper option
                    dp[i][j] = cost;
                    bracket[i][j] = "(" + bracket[i][k] + bracket[k + 1][j] + ")"; // Store parenthesization
                }
            }
        }
    }

    return bracket[1][n - 1]; // Return optimal parenthesization for full chain
}
};

/*
 * Definition:
 * The Matrix Chain Multiplication problem involves finding the most efficient way
 * to multiply a given sequence of matrices. The goal is to minimize the total number
 * of scalar multiplications needed.
 *
 * Approach:
 * - Use dynamic programming to store results in a 2D array `dp`, where `dp[i][j]`
 *   represents the minimum cost (number of multiplications) to multiply matrices from index `i` to `j`.
 * - Use another 2D array `bracket` to store the optimal parenthesization of matrices.
 * - Initialize the matrix names (A, B, C, ...) for easy identification in the output.
 * - Iterate through possible chain lengths and compute costs for each sub-chain.
 * - For each pair of starting and ending indices `(i, j)`, try every possible split point `k`
 *   and update `dp[i][j]` with the minimum cost found.
 *
 * Complexity:
 * - Time Complexity: O(n^3), where n is the number of matrices. This is due to three nested loops:
 *   one for chain length, one for starting index, and one for splitting point.
 * - Space Complexity: O(n^2) for storing results in the `dp` and `bracket` arrays.
 */
