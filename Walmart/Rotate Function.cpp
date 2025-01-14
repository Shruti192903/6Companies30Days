//Rotate Function

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long F = 0, sum = 0;

        for (int i = 0; i < n; ++i) {
            F += nums[i] * i;
            sum += nums[i];
        }

        long long maxF = F;

        for (int k = 1; k < n; ++k) {
            F = F + sum - (long long)n * nums[n - k];
            maxF = max(maxF, F);
        }

        return maxF;
    }
};


/*
 * Definition:
 * The problem involves calculating the maximum value of a rotation function 
 * for an array of integers. The rotation function is defined based on the 
 * indices and values of the elements in the array.
 *
 * Approach:
 * - First, calculate the initial value of the rotation function F(0) and 
 *   the total sum of elements in the array.
 * - Use a formula to derive subsequent values of F(k) based on F(k-1).
 * - The formula takes advantage of previously calculated values to avoid 
 *   recomputation.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the number of elements in `nums`. 
 *   We traverse the array a constant number of times.
 * - Space Complexity: O(1), as we only use a fixed amount of extra space 
 *   regardless of input size.
 */
