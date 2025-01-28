//Kth Smallest Element Query

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
 * The problem involves finding indices of the smallest numbers after trimming 
 * a specified number of digits from their right side based on multiple queries.
 *
 * Approach:
 * - For each query, use a max-heap (priority queue) to keep track of 
 *   the smallest trimmed numbers found so far.
 * - Trim each number according to the query specifications and compare 
 *   them to maintain only the required smallest values.
 *
 * Complexity:
 * - Time Complexity: O(q * n log k), where q is the number of queries, 
 *   n is the size of nums, and k is the maximum number of smallest 
 *   elements we need to keep track of for each query.
 * - Space Complexity: O(k), where k is again related to how many elements 
 *   we keep in our max-heap.
 */
