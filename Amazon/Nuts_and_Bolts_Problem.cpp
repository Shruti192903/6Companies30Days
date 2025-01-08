//Nuts and Bolts Problem
class Solution{
public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        if(n == 1) return;
        map<char, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nuts[i]]++;
        }
        int i = 0;
        for(auto it = mpp.begin(); it != mpp.end(); it++){
            nuts[i] = it->first;
            bolts[i] = it->first;
            i++;
        }
    }
};


/*
 * Definition:
 * The function matchPairs takes two arrays of characters, nuts and bolts, 
 * both of size n, and arranges them such that each nut has a corresponding 
 * bolt. The nuts and bolts are assumed to be of the same types and 
 * should match in pairs.
 *
 * Approach:
 * - Create a map to count occurrences of each character in the nuts array.
 * - Iterate through the nuts array and populate the map with counts.
 * - Use an iterator to fill both the nuts and bolts arrays with the unique 
 *   characters from the map in sorted order.
 * - This ensures that both arrays contain the same characters in the same order.
 *
 * Complexity:
 * - Time Complexity: O(n log n), where n is the number of nuts/bolts,
 *   due to the sorting of keys in the map.
 * - Space Complexity: O(n) for storing the counts in the map.
 */
