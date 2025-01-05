//Excel Sheet Column Title

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = " ";
        if( columnNumber == 0) return "";
        columnNumber--;

        // Current character
        char ch = 'A' + (columnNumber % 26);
        result = convertToTitle(columnNumber/26) + ch ;
        return result;
    }
};

/**
     * Definition:
     * The convertToTitle function converts a given column number in Excel 
     * format to its corresponding column title. For example, 1 corresponds 
     * to "A", 2 to "B", ..., 26 to "Z", 27 to "AA", and so on.
     *
     * Approach:
     * 1. If the column number is 0, return an empty string (though this 
     *    case should not occur based on the problem constraints).
     * 2. Decrement the column number by 1 to adjust for zero-based indexing.
     * 3. Calculate the current character by taking the modulo of 26 and 
     *    converting it to a character ('A' + result).
     * 4. Recursively call `convertToTitle` with the updated column number 
     *    divided by 26 to process any higher order characters.
     * 5. Concatenate the results of the recursive call with the current character 
     *    to build the full title.
     *
     * Time Complexity:
     * The time complexity is O(log n), where n is the column number. This is 
     * because we divide the column number by 26 in each recursive call.
     *
     * Space Complexity:
     * The space complexity is O(log n) due to the recursion stack in addition 
     * to storing the resulting string.
 **/
