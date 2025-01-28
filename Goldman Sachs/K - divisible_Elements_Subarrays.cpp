//K - divisible Elements Subarrays

class Solution {
public:

    int countDistinct(vector<int>& nums, int k, int p) {
        
        int n=nums.size();
        set<vector<int>>ans;
        
        int i,j;
        for(i=0;i<n;i++)
        {
            vector<int>tt;
            int ct=0;
            for(j=i;j<n;j++)
            {
                tt.push_back(nums[j]);
                if(nums[j]%p==0)
                    ++ct;
                if(ct>k)
                    break;
                ans.insert(tt);
                    
            }
        }
        return ans.size();
    }
    
};

/* Definition:
     * This function counts distinct subarrays from the input array where 
     * the number of elements divisible by a given integer does not exceed a specified limit.
     *
     * Approach:
     * - Use a nested loop to generate all possible subarrays.
     * - Maintain a counter for elements divisible by p while iterating through 
     *   each subarray. If the count exceeds k, break out of the inner loop.
     * - Store each valid subarray in a set to ensure uniqueness.
     *
     * Complexity:
     * - Time Complexity: O(n^2), where n is the length of nums. Each element 
     *   is processed multiple times to form subarrays.
     * - Space Complexity: O(n), for storing distinct subarrays in a set.
*/
