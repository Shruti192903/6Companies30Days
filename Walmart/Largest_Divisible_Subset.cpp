//Largest Divisible Subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> groupSize(n, 1), prevElement(n, -1);
        int maxIndex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && groupSize[i] < groupSize[j] + 1) {
                    groupSize[i] = groupSize[j] + 1;
                    prevElement[i] = j;
                }
            }
            if (groupSize[i] > groupSize[maxIndex]) {
                maxIndex = i;
            }
        }

        vector<int> result;
        for (int i = maxIndex; i != -1; i = prevElement[i]) {
            result.insert(result.begin(), nums[i]);
        }
        return result;
    }
};


/*
 * Definition:
 * The problem involves finding the largest subset of a given array of integers such that 
 * every pair of elements in this subset satisfies the condition that one element is divisible 
 * by the other. The goal is to return this subset.
 *
 * Approach:
 * - First, sort the input array to facilitate easy checking of divisibility.
 * - Use dynamic programming to keep track of the size of the largest divisible subset 
 *   that ends with each element and also keep track of the previous index in order to 
 *   reconstruct the subset later.
 * - For each element, check all previous elements to see if they can form a divisible 
 *   relationship and update accordingly.
 * - Finally, reconstruct the largest divisible subset using the information stored in 
 *   `prevElement`.
 *
 * Complexity:
 * - Time Complexity: O(n^2), where n is the number of elements in `nums`. This is due to 
 *   the nested loops used to build up the `groupSize` and `prevElement` arrays.
 * - Space Complexity: O(n), as we use additional space for `groupSize` and `prevElement` vectors.
 */
