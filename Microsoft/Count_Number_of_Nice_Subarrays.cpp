//Count Number of Nice Subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ansCnt = 0;
        int cnt = 0;  
        int i = 0, j = 0;

        while (j < nums.size()) {
            if (nums[j] % 2 != 0) { 
                k--; // Decrement k as we have encountered an odd number
                cnt = 0; 
            }
            
            while (k == 0) { // While we have exactly k odd numbers in the window
                if (nums[i] % 2 != 0) { 
                    k++; // Increment k as we will remove this odd number
                }
                cnt++; 
                i++; // Move the left pointer of the window to the right
            }
            
            ansCnt += cnt; // Add the count of valid subarrays to the final answer
            j++; // Move the right pointer of the window to the right
        }

        return ansCnt; // final count of subarrays 
    }
};


/**
 * Definition:
 * The function `numberOfSubarrays` counts the number of contiguous subarrays
 * in the input vector `nums` that contain exactly `k` odd numbers.
 *
 * Approach:
 * 1. Use a two-pointer (or sliding window) technique to maintain a window
 *    that contains exactly `k` odd numbers.
 * 2. The outer loop expands the right end of the window by moving pointer `j`.
 * 3. When an odd number is encountered, decrement `k`.
 * 4. If `k` becomes zero, it means we have at least `k` odd numbers in the current window.
 * 5. Use an inner loop to shrink the left end of the window by moving pointer `i`
 *    until we have fewer than `k` odd numbers.
 * 6. Count how many valid subarrays can be formed with the current window and add
 *    this count to the result.
 * 7. Continue this process until all elements in `nums` are processed.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the length of the input vector `nums`.
 *   Each element is processed at most twice (once by each pointer).
 * - Space Complexity: O(1), as only a fixed amount of additional space is used.
 */
