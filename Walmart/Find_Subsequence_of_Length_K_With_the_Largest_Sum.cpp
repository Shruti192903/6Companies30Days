//Find Subsequence of Length K With the Largest Sum

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
		// Declare variables
        int n = nums.size(), i = 0, t = k;
		// Answer Array
        vector<int> ans;
		
		// Put first k elements
        while(t>0){
            ans.push_back(nums[i]);
            i++;
            t--;
        }
		
		//Loop Through Remaining Array
        for(int j=i;j<n;j++)
        {
			// Calcualate minimum from ans array 
            int mini = min_element(ans.begin(), ans.end()) - ans.begin();
			// Comapre it with the current element
            if(ans[mini] < nums[j]){
                ans.erase(ans.begin()+mini);
                ans.push_back(nums[j]);
            }
            
        }
        return ans;
    }
};

/*
 * Definition:
 * The problem involves calculating the maximum subsequence of length k from an array of integers.
 * A subsequence is formed by deleting some elements without changing the order of remaining elements,
 * and we want to maximize the lexicographical order of this subsequence.
 *
 * Approach:
 * - Start by initializing a result vector `ans` with the first k elements from `nums`.
 * - Iterate through the remaining elements in `nums`, checking if each can replace 
 *   an existing element in `ans` (specifically, if it is greater than the smallest element in `ans`).
 * - If it can replace, remove that smallest element and add the new one.
 * - Continue this process until all elements have been considered.
 *
 * Complexity:
 * - Time Complexity: O(n*k), where n is the number of elements in `nums`. This is due to 
 *   iterating through `n` and performing a linear search for the minimum in `ans`, which can have up to `k` elements.
 * - Space Complexity: O(k), as we only store the result in a vector of size k.
 */
