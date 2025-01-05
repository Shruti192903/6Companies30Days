//First Unique Character in a String

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> frequency(26,0);
        for(char ch : s ){
            frequency[ch - 'a']++;
        }

        for(int i=0; i< s.size(); i++){
            if(frequency[s[i] - 'a'] == 1){
                return i; //index of first unique character
            }
        }
        return -1; //no unique character
    }
};

 /**
     * Definition:
     * The firstUniqChar function finds the index of the first non-repeating 
     * character in a given string `s`. If there are no non-repeating characters, 
     * it returns -1.
     *
     * Approach:
     * 1. Initialize a frequency vector of size 26 (for each lowercase letter) 
     *    to count occurrences of each character in the string.
     * 2. Iterate through the string and populate the frequency vector.
     * 3. Make a second pass through the string to find the first character 
     *    that has a frequency of 1 (indicating it is unique).
     * 4. Return the index of this character. If no unique character is found, 
     *    return -1.
     *
     * Time Complexity:
     * The time complexity is O(n), where n is the length of the input string. 
     * This is because we make two passes through the string: one for counting 
     * frequencies and another for finding the first unique character.
     *
     * Space Complexity:
     * The space complexity is O(1) since the frequency vector has a fixed size 
     * of 26, regardless of the input size.
 **/

