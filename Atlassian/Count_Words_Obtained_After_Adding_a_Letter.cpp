//Count Words Obtained After Adding a Letter

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
	// generates hashes for startWords.
        unordered_set<int> vis;
        for (string s : startWords) {
            int hash = 0;
            for (int i = 0; i < s.size(); i++) {
                hash += (1 << (s[i] - 'a'));
            }
            vis.insert(hash);
        }
        
		// check each target Word
        int res = 0;
        for (string s : targetWords) {
            int hash = 0;
            // k is the index of character we remove
            for (int k = 0; k < s.size(); k++) {
                hash = 0;
                for (int i = 0; i < s.size(); i++) {
                    if (i == k) continue;
                    hash += (1 << (s[i] - 'a'));
                }
                if (vis.count(hash)) {
                    res++;
                    break;
                }
            }
        }
        
        return res;
    }
};

/*
 * Definition:
 * The problem involves determining how many target words can be formed 
 * by adding a single letter to any of the given start words. Each 
 * target word can have one character removed to check against 
 * the start words.
 *
 * Approach:
 * - Use bit manipulation to create a unique hash for each start word, 
 *   where each bit represents whether a specific character is present.
 * - For each target word, try removing each character and calculate 
 *   its corresponding hash. If this hash exists in the set of start 
 *   word hashes, it means we can form this target word by adding 
 *   one letter.
 *
 * Complexity:
 * - Time Complexity: O(N * M^2), where N is the number of target words 
 *   and M is the maximum length of a target word. We iterate over each 
 *   character in each target word and check against all characters.
 * - Space Complexity: O(K), where K is the number of unique characters 
 *   in start words, used for storing hashes in an unordered set.
 */
