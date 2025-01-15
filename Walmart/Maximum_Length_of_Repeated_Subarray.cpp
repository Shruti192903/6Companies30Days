//Maximum Length of Repeated Subarray

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        
        if (A.size() < B.size()) swap(A, B);
        int M = A.size(), N = B.size();
        vector<int> dp(N + 1, 0);
        int ans = 0;
        
        for(int i = 0; i < M; i++) {
            for(int j = N - 1; j >= 0; j--) {
                
                if (A[i] == B[j]) {
                    dp[j + 1] = 1 + dp[j];
                } else {
                    dp[j + 1] = 0;
                }
                              
                ans = max(ans, dp[j + 1]);
            }            
        }        
        return ans;
    }
};


/*
 * Definition:
 * The problem involves finding the length of the longest common subarray between two arrays.
 * A common subarray is defined as a contiguous part of both arrays that is identical.
 *
 * Approach:
 * - Use dynamic programming to keep track of lengths of common subarrays using a single 
 *   dimensional DP array.
 * - Iterate through each element in A and for each element, iterate through B in reverse 
 *   order to avoid overwriting values in dp that are needed for calculation.
 * - If elements match, increment the length of the common subarray; if they don't, reset 
 *   the value in dp.
 *
 * Complexity:
 * - Time Complexity: O(M * N), where M and N are the lengths of arrays A and B respectively.
 *   We iterate through both arrays to fill in the DP table.
 * - Space Complexity: O(N), as we use a single-dimensional DP array of size N + 1.
 */
