//Maximum Sum of Distinct Subarrays With Length K

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> elements;
        long long current_sum = 0;
        long long max_sum = 0;
        int begin = 0;
        
        for (int end = 0; end < n; end++) {
            if (elements.find(nums[end]) == elements.end()) {
                current_sum += nums[end];
                elements.insert(nums[end]);
                
                if (end - begin + 1 == k) {
                    max_sum = max(max_sum, current_sum);
                    current_sum -= nums[begin];
                    elements.erase(nums[begin]);
                    begin++;
                }
            } else {
                while (nums[begin] != nums[end]) {
                    current_sum -= nums[begin];
                    elements.erase(nums[begin]);
                    begin++;
                }
                begin++;
            }
        }
        
        return max_sum;
    }
};

 /**
     * Definition:
     * The maximumSubarraySum function calculates the maximum sum of any 
     * contiguous subarray of length k from the given vector of integers, 
     * ensuring that all elements in that subarray are unique.
     *
     * Approach:
     * 1. Initialize variables to keep track of the current sum of the window,
     *    the maximum sum found, and a set to store unique elements.
     * 2. Use a sliding window approach with two pointers (begin and end).
     * 3. Iterate through the array using the end pointer:
     *    - If the current element is unique (not in the set), add it to 
     *      the current sum and insert it into the set.
     *    - If the window size reaches k, update the maximum sum if needed,
     *      then remove the element at the beginning of the window from 
     *      both the sum and the set, and move the begin pointer forward.
     *    - If a duplicate is found, remove elements from the beginning of 
     *      the window until all elements are unique again.
     * 4. Return the maximum sum found after processing all elements.
     *
     * Time Complexity: O(n), where n is the number of elements in nums.
     * Space Complexity: O(k), as we store at most k unique elements in 
     *                  an unordered set.
  **/
