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
        
        return ans.size(); 
    }
};

/*
 * Definition:
 * The problem involves finding the maximum number of envelopes that can be 
 * Russian-dolled, meaning one envelope can fit inside another if its width 
 * and height are both strictly less than those of the other envelope.
 *
 * Approach:
 * - Sort the envelopes first by width in ascending order. If two envelopes 
 *   have the same width, sort them by height in descending order.
 * - Use dynamic programming with binary search to find the longest increasing 
 *   subsequence based on height.
 *
 * Complexity:
 * - Time Complexity: O(n log n), where n is the number of envelopes. Sorting takes 
 *   O(n log n) and finding the longest increasing subsequence takes O(n log n).
 * - Space Complexity: O(n), for storing the heights in the `ans` vector.
 */
