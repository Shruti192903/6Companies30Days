//Russian Doll Envelopes

using namespace std;

class Solution {
public:
    static bool comp(vector<int>& a , vector<int>& b) {
        // Sort by width ascending; if equal, sort by height descending
        if (a[0] == b[0]) {
            return a[1] > b[1]; // Descending order for height
        }
        return a[0] < b[0]; // Ascending order for width
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> ans; 
        
        for (auto& e : envelopes) {
            // If ans is empty or current height is greater than last in ans
            if (ans.empty() || e[1] > ans.back()) {
                ans.push_back(e[1]); // Add current height
            } else {
                int index = lower_bound(ans.begin(), ans.end(), e[1]) - ans.begin();
                ans[index] = e[1]; // Replace with current height
            }
        }
        
        return ans.size(); // maximum number of envelopes
    }
};


/**
 * Definition:
 * The `Solution` class contains a method `maxEnvelopes` which takes a 2D vector `envelopes`
 * representing the dimensions of envelopes. Each envelope is defined by its width and height.
 * The function returns the maximum number of envelopes that can be nested inside each other.
 *
 * Approach:
 * 1. Sort the envelopes:
 *    - Sort by width in ascending order.
 *    - If two envelopes have the same width, sort by height in descending order.
 *      This prevents envelopes with the same width from being counted as valid nesting options.
 * 2. Use a dynamic programming approach to find the longest increasing subsequence (LIS) based on height:
 *    - Initialize an empty vector `ans` to store heights of the valid envelopes.
 *    - For each envelope, check if its height can extend the current sequence:
 *      - If it can, add it to `ans`.
 *      - If not, use binary search (`lower_bound`) to find its position and replace the existing value
 *        to maintain a potential increasing sequence.
 *
 * Complexity:
 * - Time Complexity: O(n log n), where n is the number of envelopes. This is due to sorting and binary search operations.
 * - Space Complexity: O(n) for storing the heights in the `ans` vector.
 */
