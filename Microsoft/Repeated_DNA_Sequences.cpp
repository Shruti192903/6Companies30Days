//Repeated DNA Sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> repeatedSequences;
        unordered_map<string, int> sequenceCount;

        //Base Case
        if(s.length() <= 10){
            return repeatedSequences;
        }

        for(int i=0; i<= s.length()-10; i++){
            string currentSequence = s.substr(i,10);
            sequenceCount[currentSequence]++;
        }

        //For sequences that occur more than once
        for(auto& entry: sequenceCount){
            if(entry.second > 1){
                repeatedSequences.push_back(entry.first); // Add repeated sequences
            }
        }
        return repeatedSequences;
    }
};

/**
     * Definition:
     * The findRepeatedDnaSequences function identifies all 10-letter long sequences 
     * (substrings) that occur more than once in a given DNA string. Each sequence is 
     * composed of the characters 'A', 'C', 'G', and 'T'.
     *
     * Approach:
     * 1. Initialize a vector to store repeated sequences and an unordered map to count 
     *    occurrences of each 10-letter sequence.
     * 2. Check if the length of the input string is less than or equal to 10; if so, 
     *    return an empty vector since no sequences can be formed.
     * 3. Iterate through the DNA string, extracting every possible 10-letter sequence 
     *    using substrings.
     * 4. For each extracted sequence, increment its count in the unordered map.
     * 5. After counting, iterate through the map and collect sequences that appear more 
     *    than once into the result vector.
     *
     * Time Complexity:
     * The time complexity is O(n), where n is the length of the input string. 
     * This is because we make a single pass through the string to extract sequences and another 
     * pass through the map to collect repeated sequences. The space complexity is also 
  **/
