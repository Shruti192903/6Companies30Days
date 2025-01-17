//Word Break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (const string& w : wordDict) {
                int start = i - w.length();
                if (start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];        
    }
};

/*
 * Definition:
 * The problem involves determining if a given string can be segmented into a space-separated 
 * sequence of one or more dictionary words. The dictionary is provided as an array of strings.
 *
 * Approach:
 * - Use dynamic programming to solve the problem by building a DP array where dp[i] indicates 
 *   whether the substring s[0..i-1] can be segmented into words from the dictionary.
 * - Iterate through each position in the string and check all words in the dictionary to see 
 *   if they match the end of the current substring.
 *
 * Complexity:
 * - Time Complexity: O(n * m), where n is the length of the string and m is the number of words 
 *   in the dictionary. In the worst case, we may check every word for every character in the string.
 * - Space Complexity: O(n), as we use a DP array of size n + 1 to store results.
 */
