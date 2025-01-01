// Minimum Moves to Equal Array Elements II

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int size = nums.size();

        // Finding median
        sort(nums.begin(), nums.end());
        int median = nums[size/2];

        int left_sum =0;
        int right_sum = 0;

        for(int i=0; i<size; i++){
            if(nums[i] < median){
                left_sum += (median - nums[i]) ; // Moves needed for left side elements
            }else if(nums[i] > median){
                right_sum += (nums[i] - median) ; // Moves needed for right side elements
            }
        }
        return left_sum + right_sum; // Total moves
    }
};

/* Problem Statement:
 * Given an integer array nums of size n, return the minimum number of moves required
 * to make all array elements equal. In one move, you can increment or decrement an element
 * by 1.
 *
 * Approach:
 * To find the minimum moves to equalize the array elements:
 * 1. Sort the array.
 * 2. Find the median.
 * 3. Calculate total moves needed to make all elements equal to the median.
 */
/*
 * Complexity Analysis:
 * - Time Complexity: O(n log n) - The sorting step takes O(n log n) time.
 * - Space Complexity: O(1) - The solution uses a constant amount of space.
 */
