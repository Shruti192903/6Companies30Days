//LRU Cache

class LRUCache
{
    public:
        list<pair<int,int>> l;
        unordered_map<int,list<pair<int, int>>::iterator> m;
        int size;
        LRUCache(int capacity)
        {
            size=capacity;
        }
        int get(int key)
        {
            if(m.find(key)==m.end())
                return -1;
            l.splice(l.begin(),l,m[key]);
            return m[key]->second;
        }
        void put(int key, int value)
        {
            if(m.find(key)!=m.end())
            {
                l.splice(l.begin(),l,m[key]);
                m[key]->second=value;
                return;
            }
            if(l.size()==size)
            {
                auto d_key=l.back().first; // Get the key of the least recently used item
                l.pop_back();
                m.erase(d_key);
            }
            l.push_front({key,value});
            m[key]=l.begin();
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
 * Definition:
 * The problem involves implementing an LRU Cache that supports 
 * retrieving values by keys and updating or inserting new values 
 * while maintaining a limited capacity. When capacity is exceeded, 
 * the least recently used item should be removed.
 *
 * Approach:
 * - Use a doubly linked list to maintain order of usage and an 
 *   unordered map for O(1) access to keys.
 * - On retrieval (`get`), move accessed items to the front of 
 *   the list. On insertion (`put`), check for existing keys and 
 *   update or add new keys while managing capacity.
 *
 * Complexity:
 * - Time Complexity: O(1) for both `get` and `put` operations due 
 *   to efficient use of data structures.
 * - Space Complexity: O(capacity), where capacity is the maximum 
 *   number of items stored in the cache.
 */
