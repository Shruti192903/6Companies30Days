//K-diff Pairs in an Array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> a;
    //Count the frequency of each number in nums
        for(int i:nums)
            a[i]++;
        int ans=0;
        for(auto x:a)
        {
            if(k==0)
            {    
                if(x.second>1)
                ans++;
            }
             else if(a.find(x.first+k)!=a.end())
                ans++;
        }
        
        return ans;
    }
};

/*
 * Definition:
 * The problem involves finding the number of unique pairs (i, j) in an array such that 
 * the absolute difference between them is equal to a given value k. A pair (i, j) is considered 
 * unique if i != j.
 *
 * Approach:
 * - Use an unordered map to count the frequency of each number in the input array.
 * - Iterate through this map:
 *   - If k is 0, check for numbers that appear more than once (duplicates).
 *   - If k is greater than 0, check if there exists a number that is equal to 
 *     the current number plus k.
 * - Count these valid pairs and return the total count.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the number of elements in `nums`. We traverse 
 *   the array once to build the frequency map and then traverse it again to count pairs.
 * - Space Complexity: O(n), as we use additional space for the frequency map.
 */
