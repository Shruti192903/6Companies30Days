//Top K Frequent Words

struct Compare {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(int i=0; i<words.size(); i++)
            m[words[i]]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;
        for(auto p : m)
            q.push({p.second, p.first});
        
        vector<string> ans;
        while(k--) {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};

/*
 * Definition:
 * The problem involves finding the top k most frequent words from a list. 
 * If two words have the same frequency, they should be sorted in lexicographical order.
 *
 * Approach:
 * - Use an unordered map to count how many times each word appears.
 * - Use a priority queue (min-heap) to keep track of the top k frequent words.
 * - The custom comparator ensures that if two words have the same frequency,
 *   they are sorted in ascending lexicographical order.
 *
 * Complexity:
 * - Time Complexity: O(n log k), where n is the number of words. We process each word 
 *   once and push/pop from the priority queue which takes log k time.
 * - Space Complexity: O(n), as we store all unique words in the map and potentially 
 *   in the priority queue.
 */
