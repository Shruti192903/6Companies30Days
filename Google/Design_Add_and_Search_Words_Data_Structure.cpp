//Design Add and Search Words Data Structure

class WordDictionary
{
     unordered_map<int, vector<string>> words;

     bool isEqual(string word1, string word2)
     {
          for (int i = 0; i < word1.size(); i++)
          {
               if (word2[i] == '.')
                    continue;
               if (word1[i] != word2[i])
                    return false;
          }
          return true;
     }

public:
     WordDictionary() {}

     void addWord(string word)
     {
          words[word.size()].push_back(word);
     }

     bool search(string word)
     {
          for (auto &&s : words[word.size()])
               if (isEqual(s, word))
                    return true;
          return false;
     }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


/*
 * Definition:
 * The WordDictionary class provides a data structure to store words and 
 * supports searching for words with the ability to include wildcards 
 * represented by '.' which can match any single character.
 *
 * Approach:
 * - Use an unordered map to group words by their lengths, allowing for 
 *   efficient retrieval based on the length of the search query.
 * - Implement a helper function to compare two words, allowing for 
 *   wildcards in the search string.
 * - When searching for a word, check all words of the same length and 
 *   use the helper function to determine if they match.
 *
 * Complexity:
 * - Time Complexity:
 *   - Add Word: O(1) on average, as inserting into a vector is amortized constant time.
 *   - Search: O(m * n), where m is the number of words of the same length and n is 
 *     the length of those words (in worst case).
 * - Space Complexity: O(N), where N is the total number of characters in all added words.
 */
