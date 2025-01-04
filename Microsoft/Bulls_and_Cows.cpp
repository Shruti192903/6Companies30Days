//Bulls and Cows

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;

        vector<int> s(10,0);
        vector<int> g(10,0);

        for(int i=0; i<secret.length(); i++){
            if(secret[i] == guess[i]){
                bulls++; //Same element at same index
            }else{ //Same element at different indices
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }

        for(int i=0; i<10; i++){
            cows += min(s[i], g[i]); // take min count of each digit from both vectors
        }

        string hint = " ";
        hint = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return hint; 
    }
};


 /**
     * Definition:
     * The getHint function takes two strings, `secret` and `guess`, which represent 
     * a secret number and a guessed number, respectively. The function calculates 
     * the number of "bulls" and "cows" based on the rules of the game:
     * - Bulls: The number of digits that are correct and in the correct position.
     * - Cows: The number of digits that are correct but in the wrong position.
     *
     * Approach:
     * 1. Initialize counters for bulls and cows.
     * 2. Create two vectors to count occurrences of each digit (0-9) in the secret 
     *    and guess strings for positions that are not bulls.
     * 3. Iterate through each character in both strings:
     *    - If characters at the same index are equal, increment the bulls counter.
     *    - If they are not equal, increment the count for that digit in the respective vector.
     * 4. After counting bulls, iterate through the digit counts to calculate cows by 
     *    taking the minimum count of each digit from both vectors.
     * 5. Construct the hint string in the format "xAyB", where x is the number of bulls 
     *    and y is the number of cows.
     *
     * Time Complexity:
     * The time complexity is O(n), where n is the length of the input strings. 
     * This is because we make a single pass through both strings to count bulls 
     * and digit occurrences, followed by a constant time operation to calculate cows.
 **/
