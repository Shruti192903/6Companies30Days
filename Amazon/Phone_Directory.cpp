//Phone Directory

class Solution{
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> child;
        vector<string> list;
    };
    
    TrieNode* root;
    TrieNode* p;
    
    void insert(string s){
        TrieNode* p = root;
        for (char c : s) {
            if (p->child[c] == NULL) p->child[c] = new TrieNode();
            p = p->child[c];
            p->list.push_back(s);
        }
    }   
    
    vector<string> query(char c){
        if (p == NULL || p->child[c] == NULL) {
            p = NULL;
            return {"0"};
        }
        
        p = p->child[c];
        return p->list;
    }
    
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        root = new TrieNode();
        p = root;
        // Insert all contacts into the Trie
        for (int i = 0; i < n; ++i){
            insert(contact[i]);
        }
        
        
        vector<vector<string>> ans;
        for (int i = 0; i < s.length(); ++i){
            vector<string> list = query(s[i]); //Getting matching contacts for current prefix
            sort(list.begin(), list.end());
            list.erase(unique(list.begin(), list.end()), list.end());
            ans.push_back(list);
        }
        
        return ans;
    }
};

/*
 * Definition:
 * The problem involves displaying contacts based on a given prefix string.
 * Given an array of contact names and a search string, the goal is to return
 * a list of contacts that match each prefix formed by the characters of the search string.
 *
 * Approach:
 * - Use a Trie data structure to store the contact names. Each node in the Trie
 *   contains a map of child nodes and a list of strings representing contact names
 *   that share the same prefix.
 * - The `insert` function adds each contact to the Trie, updating the list at each node.
 * - The `query` function retrieves all contacts that match the current prefix based on
 *   the characters in the search string.
 * - In the `displayContacts` function, first, all contacts are inserted into the Trie.
 *   Then, for each character in the search string, it queries the Trie and sorts
 *   the results while removing duplicates before adding them to the final answer.
 *
 * Complexity:
 * - Time Complexity: O(N * M + S * log(S)), where N is the number of contacts,
 *   M is the average length of each contact name, and S is the total number of results
 *   returned for all queries. The log(S) factor comes from sorting and removing duplicates.
 * - Space Complexity: O(N * M), where N is the number of contacts and M is their average length,
 *   due to storing contacts in the Trie and lists at each node.
 */
