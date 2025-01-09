//Best Time to Buy and Sell Stock IV

class Solution {
public:
    int dp[1005][105][2];
    int f(vector<int>& v, int i, int k, bool on){
        if(i >= v.size()) 
            return 0; //no prices to process

        if(dp[i][k][on] != -1) 
            return dp[i][k][on];
        
         int profit = 0;
        //Skipping current price
        profit = max(profit, f(v, i + 1, k, on));
        
        if (on) {
            profit = max(profit, v[i] + f(v, i + 1, k - 1, 0)); // Sell current stock
        } 
        //Buy stock if not currently holding and still have transactions left
        else if (k) {
            profit = max(profit, f(v, i + 1, k, 1) - v[i]); 
        }
        
        return dp[i][k][on] = profit; 
    }

    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof dp); 
        return f(prices, 0, k, 0); // Starting recursion from index 0 with k transactions allowed
    }
};

/*
 * Definition:
 * The problem requires finding the maximum profit from at most k transactions
 * on given stock prices over time. Each transaction consists of buying and then selling one share.
 *
 * Approach:
 * - Use dynamic programming with memoization to avoid recalculating results for the same state.
 * - Define a recursive function `f` that takes the current index `i`, remaining transactions `k`,
 *   and a boolean `on` indicating whether we currently hold a stock.
 * - Base Case: If we have processed all prices (i.e., index `i` is out of bounds), return 0.
 * - If we have already computed the result for this state (`dp[i][k][on]`), return it.
 * - Calculate the maximum profit by considering two scenarios:
 *   1. Not making any transaction at index `i`.
 *   2. If we are holding a stock (`on == true`), we can sell it.
 *   3. If we are not holding a stock (`on == false`) and still have transactions left, we can buy it.
 * - Store the result in `dp[i][k][on]` before returning it.
 *
 * Complexity:
 * - Time Complexity: O(n * k), where n is the number of prices and k is the maximum number of transactions.
 * - Space Complexity: O(n * k) for the DP table used for memoization.
 */
