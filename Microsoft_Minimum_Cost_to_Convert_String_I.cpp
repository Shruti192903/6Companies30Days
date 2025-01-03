// Minimum Cost to Convert String I

#include <vector>
#include <string>
#include <limits>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = LLONG_MAX;
        int numChars = 26;
        vector<vector<long long>> conversionCost(numChars, vector<long long>(numChars, INF));

        // Initialize the conversion cost from each character to itself as zero
        for (int i = 0; i < numChars; ++i) {
            conversionCost[i][i] = 0;
        }

        // Fill in the direct conversion costs based on the original and changed characters
        for (int i = 0; i < original.size(); ++i) {
            int fromChar = original[i] - 'a';
            int toChar = changed[i] - 'a';
            conversionCost[fromChar][toChar] = min(conversionCost[fromChar][toChar], (long long)cost[i]);
        }

        // Floyd-Warshall algorithm to find the minimum conversion costs between all pairs of characters
        for (int intermediateChar = 0; intermediateChar < numChars; ++intermediateChar) {
            for (int srcChar = 0; srcChar < numChars; ++srcChar) {
                for (int tgtChar = 0; tgtChar < numChars; ++tgtChar) {
                    if (conversionCost[srcChar][intermediateChar] < INF && conversionCost[intermediateChar][tgtChar] < INF) {
                        conversionCost[srcChar][tgtChar] = min(conversionCost[srcChar][tgtChar], 
                                                                conversionCost[srcChar][intermediateChar] + conversionCost[intermediateChar][tgtChar]);
                    }
                }
            }
        }

        long long totalCost = 0;
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] != target[i]) {
                int srcChar = source[i] - 'a';
                int tgtChar = target[i] - 'a';
                if (conversionCost[srcChar][tgtChar] == INF) {
                    return -1; // If no valid conversion exists
                }
                totalCost += conversionCost[srcChar][tgtChar];
            }
        }
        
        return totalCost < INF ? totalCost : -1;
    }
};

 /**
     * Definition:
     * The minimumCost function calculates the minimum cost to convert a source string 
     * into a target string using a set of character conversion rules. Each conversion 
     * rule specifies a cost to change one character into another.
     *
     * Approach:
     * 1. Initialize a 2D vector `conversionCost` to store the minimum cost of converting 
     *    each character to every other character. Initially, set all costs to infinity 
     *    (except for self-conversions which are zero).
     * 2. Populate the `conversionCost` matrix with direct conversion costs from the 
     *    `original` characters to the `changed` characters.
     * 3. Use the Floyd-Warshall algorithm to compute the minimum conversion costs between 
     *    all pairs of characters, allowing for intermediate conversions.
     * 4. Iterate through each character in the source and target strings:
     *    - If the characters differ, check if a valid conversion exists.
     *    - If it does, accumulate the total conversion cost.
     * 5. Return the total cost if it's valid; otherwise, return -1 if any conversion is impossible.
     *
     * Time Complexity:
     * The time complexity is O(26^3) due to the Floyd-Warshall algorithm, where 26 is 
     * the number of lowercase English letters. This results in a constant time complexity 
     * since it does not depend on input size but rather on the fixed number of characters.
     **/
