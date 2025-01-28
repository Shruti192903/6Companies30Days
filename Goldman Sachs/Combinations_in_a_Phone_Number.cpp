//Combinations in a Phone Number

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        if (digits.empty()) {
            return res;
        }
        
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        backtrack(digits, 0, "", res, digitToLetters);
        
        return res;        
    }

    void backtrack(const string& digits, int idx, string comb, vector<string>& res, const unordered_map<char, string>& digitToLetters) {
        if (idx == digits.length()) {
            res.push_back(comb);
            return;
        }
        
        string letters = digitToLetters.at(digits[idx]);
        for (char letter : letters) {
            backtrack(digits, idx + 1, comb + letter, res, digitToLetters);
        }
    }    
};

    /**
     * Definition:
     * This function takes a string of digits and returns all possible 
     * letter combinations that can be formed by mapping each digit 
     * to its corresponding letters on a phone keypad.
     *
     * Approach:
     * - Use backtracking to explore all combinations recursively.
     * - Maintain a mapping of digits to their corresponding letters.
     * - For each digit, iterate through its letters and recursively 
     *   build combinations until all digits are processed.
     *
     * Complexity:
     * - Time Complexity: O(4^n), where n is the length of the input 
     *   digits. Each digit can map to 3 or 4 letters, leading to 
     *   exponential growth in combinations.
     * - Space Complexity: O(n), for storing the current combination 
     *   during recursion and O(m) for the result storage, where m 
     *   is the number of combinations generated.
     */
