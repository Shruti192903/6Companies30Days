//Extra Characters in a String

class Solution {
public:
    unordered_set<string> st;
    vector<int> mem;

    int solve(string& s, int ind){ 
        if(ind >= s.size()) {
            return 0;
        }
        if(mem[ind] != -1) {
            return mem[ind];
        }
        int res = 1 + solve(s, ind + 1); 
        for(int i = 1; ind + i <= s.size(); ++i){ 
            string t = s.substr(ind, i);
            if(st.find(t) != st.end()){
                res = min(res, solve(s, ind+i));
            } 
        }
        return mem[ind] = res;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        mem.resize(s.size() + 1, -1);
        for(auto d: dictionary ) st.insert(d);
        return solve(s, 0);
    }
};

/*
 * Definition:
 * The problem involves determining the minimum number of extra characters in a string 
 * that cannot be formed using words from a given dictionary. The goal is to minimize 
 * these extra characters by checking all possible substrings against the dictionary.
 *
 * Approach:
 * - Use recursion with memoization to efficiently compute results for overlapping subproblems.
 * - Maintain a set for quick lookups of dictionary words.
 * - For each index in the string, consider both taking an extra character and matching 
 *   substrings against the dictionary.
 *
 * Complexity:
 * - Time Complexity: O(n^2), where n is the length of the input string. In the worst case,
 *   we may check all substrings starting from each index.
 * - Space Complexity: O(n), due to the memoization array and storage for the set of words.
 */
