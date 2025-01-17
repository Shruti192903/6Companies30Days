//Sort Characters By Frequency

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>charFreq;
        for(auto ch : s){
            charFreq[ch]++;
        }
        string ans="";
        while(charFreq.size()>0){
            int maxcount=INT_MIN;
            char ch;
            for(const auto& pair : charFreq){
                if(pair.second > maxcount){
                    maxcount=pair.second;
                    ch=pair.first;
                }
            }
            for(int i=0;i<maxcount;i++){
                    ans+=ch;
                }
            charFreq.erase(ch);
        }
        return ans;
    }
};

/*
 * Definition:
 * The problem involves sorting characters in a string based on their frequency. 
 * Characters that appear more frequently should come before those that appear less frequently.
 *
 * Approach:
 * - Use an unordered map to count how many times each character appears in the input string.
 * - Iterate until all characters have been processed:
 *   - Find the character with the highest frequency.
 *   - Append it to the result string as many times as its frequency.
 *   - Remove that character from the map.
 *
 * Complexity:
 * - Time Complexity: O(n^2), where n is the length of the input string. The outer loop runs 
 *   for each unique character, and finding the maximum frequency takes O(n) in the worst case.
 * - Space Complexity: O(n), as we use a map to store frequencies of characters.
 */
