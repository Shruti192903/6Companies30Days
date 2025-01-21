//Query Kth Smallest Trimmed Number

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto x:queries)
        {
            priority_queue<pair<string,int>> v;
            for(int i=0;i<nums.size();i++)
            {
                int t=nums[i].length()-x[1];
                string p=nums[i].substr(t,x[1]);
                if(v.size()<x[0])
                    v.push({p,i});
                else
                {
                    if(v.top().first > p)
                    {
                        v.pop();
                        v.push({p,i});
                    }
                }
            }
            int val=v.top().second;
            res.push_back(val);
        }
        return res;
    }
};


/*
 * Definition:
 * The problem involves maximizing the product of an array after performing 
 * a specified number of increments on its elements. Each increment can only 
 * be applied to one element at a time.
 *
 * Approach:
 * - Use a min-heap (priority queue) to efficiently access and increment 
 *   the smallest element in the array.
 * - Perform k increments by continually extracting the smallest element, 
 *   incrementing it, and pushing it back into the heap.
 * - After all increments are done, calculate the product of all elements 
 *   in the heap, taking care to apply modulo at each step to prevent overflow.
 *
 * Complexity:
 * - Time Complexity: O(n + k log n), where n is the number of elements in 
 *   nums. We push all elements into the heap and perform k operations on it.
 * - Space Complexity: O(n), as we store all elements in a priority queue.
 */
