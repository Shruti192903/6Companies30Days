//Find Beautiful Indices in the Given Array I

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ans, indices_a, indices_b;
        
        // Lengths of strings
        int x = s.size(), y = a.size(), z = b.size();
        
        //Find indices of occurrences of string 'a'
        for (int i = 0; i <= x - y; i++) {
            if (s.substr(i, y) == a) {
                indices_a.push_back(i);
            }
        }
        
        //Find indices of occurrences of string 'b'
        for (int j = 0; j <= x - z; j++) {
            if (s.substr(j, z) == b) {
                indices_b.push_back(j);
            }
        }
        
        for (int i = 0; i < indices_a.size(); i++) {
            for (int j = 0; j < indices_b.size(); j++) {
                // Check if substrings match and absolute difference <= k
                if (abs(indices_a[i] - indices_b[j]) <= k) {
                    ans.push_back(indices_a[i]);
                    break;
                }
            }
        }
        
        //Sort the beautiful indices in ascending order
        sort(ans.begin(), ans.end());
                return ans;
    }
};

/*
 * Definition:
 * The problem involves finding "beautiful" indices in a given string where 
 * occurrences of two specified substrings are located within a certain distance 
 * from each other.
 *
 * Approach:
 * - First, find all starting indices of substring 'a' and store them in a list.
 * - Then, find all starting indices of substring 'b' and store them in another list.
 * - For each index in 'a', check against all indices in 'b' to see if their 
 *   absolute difference is less than or equal to k. If so, add it to the result.
 *
 * Complexity:
 * - Time Complexity: O(N*M), where N is the number of occurrences of 'a' and 
 *   M is the number of occurrences of 'b'. Each occurrence pair is checked.
 * - Space Complexity: O(N + M), used for storing the lists of occurrences.
 */
