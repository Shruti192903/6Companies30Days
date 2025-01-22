//Design Add and Search Words Data Structure

class TrieNode {
public:
    bool word;
    TrieNode* children[26];
    TrieNode() {
        word = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node -> children[c - 'a']) {
                node -> children[c - 'a'] = new TrieNode();
            }
            node = node -> children[c - 'a'];
        }
        node -> word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word.c_str(), root);
    }
private:
    TrieNode* root = new TrieNode();
    
    bool search(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node -> children[word[i] - 'a'];
            } else {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> children[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node -> word;
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
 * - Use a trie (prefix tree) to efficiently store and retrieve words.
 * - Implement an addWord method to insert words into the trie.
 * - Implement a search method that allows for wildcards by recursively 
 *   checking all possible paths in the trie.
 *
 * Complexity:
 * - Time Complexity:
 *   - Add Word: O(m), where m is the length of the word being added.
 *   - Search: O(m * 26^d), where m is the length of the word being searched 
 *     and d is the number of wildcards (in worst case).
 * - Space Complexity: O(N), where N is the total number of characters in all added words.
 */
