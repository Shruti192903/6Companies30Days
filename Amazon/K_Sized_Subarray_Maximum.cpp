//K Sized Subarray Maximum

class Solution{
public:
    public:
    vector<int> maxOfSubarrays(vector<int>& nums, int k) {
        vector<int> ans; 
        deque<int> dq; 
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i); 
            
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]); 
            }
        }
        
        return ans; 
    }
};

/**
     * Definition:
     * The maxOfSubarrays function computes the maximum value for each 
     * contiguous subarray of size k from the given vector of integers. 
     * It returns a vector containing these maximum values.
     *
     * Approach:
     * 1. Initialize a result vector `ans` to store the maximums and 
     *    a deque `dq` to keep track of indices of useful elements.
     * 2. Loop through each element in the input array:
     *    - Remove indices from the front of the deque if they are out 
     *      of the bounds of the current window (i.e., if they are 
     *      less than `i - k`).
     *    - Remove indices from the back of the deque while the current 
     *      element is greater than or equal to the elements at those 
     *      indices, as they cannot be maximums for future windows.
     *    - Add the current index to the back of the deque.
     *    - If we have processed at least `k` elements, add the maximum 
     *      for this window (the element at the front of the deque) to `ans`.
     * 3. Return `ans`, which contains the maximum values for each subarray of size k.
     *
     * Time Complexity: O(n), where n is the number of elements in nums. 
     *                 Each element is added and removed from the deque at most once.
     *
     * Space Complexity: O(k), as we store at most k indices in the deque at any time.
   **/
