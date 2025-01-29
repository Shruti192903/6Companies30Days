//Run Length Encoding

class Solution{
  public:
    string encode(string s) {
        int n = s.size();
        string ans = "";
        for(int i =0;i< s.size();i++)
        {
            int count = 1;
            while(i+1 < n and s[i] == s[i+1])
            {
                count++;
                i++;
            }
            ans += s[i];
            ans += to_string(count);
        }
        return ans;
    }
};


/*
 * Definition:
 * This function implements Kadane's Algorithm to find the maximum sum of 
 * contiguous subarrays within a given array. It efficiently calculates 
 * the maximum subarray sum in linear time.
 *
 * Approach:
 * - Initialize two variables: `maxSum` to store the overall maximum sum 
 *   found so far, and `currentSum` to track the sum of the current subarray.
 * - Iterate through each element of the array:
 *   - Update `currentSum` by adding the current element.
 *   - If `currentSum` exceeds `maxSum`, update `maxSum`.
 *   - If `currentSum` drops below zero, reset it to zero (start a new subarray).
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the number of elements in the input array. 
 *   Each element is processed once.
 * - Space Complexity: O(1), as we use a constant amount of space for variables.
 */
