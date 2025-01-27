//Length of Longest Subarray With at Most K Frequency

class Solution {
public:

    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
          
            unordered_map<int,int> mp;
              
               int i=0;
               int j=0;

                   int count=0;

                     while(j<n){
                            mp[nums[j]]++;

                            while(i<j and mp[nums[j]]>k){
                                  mp[nums[i]]--;
                                  i++;
                            }
                               count  = max(count, j-i+1);
                               j++;
                     }
                     return count;
    }
};


/*
 * Definition:
 * The problem involves finding the longest contiguous subarray in which 
 * no element appears more than k times.
 *
 * Approach:
 * - Use a sliding window technique with two pointers (i and j) to maintain 
 *   a range of elements that satisfy the condition.
 * - Use a hash map to keep track of how many times each number appears 
 *   in the current window.
 * - Adjust the left pointer when any number's occurrence exceeds k.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the length of nums. Each element 
 *   is processed at most twice (once by each pointer).
 * - Space Complexity: O(m), where m is the number of unique elements in 
 *   nums that are counted in the hash map.
 */
