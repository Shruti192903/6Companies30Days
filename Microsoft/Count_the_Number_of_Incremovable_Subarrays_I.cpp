// Count the Number of Incremovable Subarrays I

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int incremovableCount = 0; // Count of incremovable subarrays
        int arraySize = nums.size();
        
        // Outer loop for the start index of the subarray
        for (int startIndex = 0; startIndex < arraySize; startIndex++) {
            // Inner loop for the end index of the subarray
            for (int endIndex = startIndex; endIndex < arraySize; endIndex++) {
                bool isIncremovable = true; // Flag to check if subarray is incremovable
                int lastElement = -1;
                
                // Loop to check each element within or outside the subarray
                for (int currentIndex = 0; currentIndex < arraySize; currentIndex++) {
                    if (currentIndex >= startIndex && currentIndex <= endIndex) {
                        // Elements within the subarray are skipped
                    } else {
                        isIncremovable &= (lastElement < nums[currentIndex]); // Check if the current element is greater than the last one
                        lastElement = nums[currentIndex]; // Update the last element
                    }
                }
                
                incremovableCount += isIncremovable; 
            }
        }
        return incremovableCount; // Return the total count of "incremovable" subarrays
    }
};


 /**
     * Definition:
     * An "incremovable" subarray is a contiguous subarray that can be removed from the array 
     * such that the remaining elements still form a strictly increasing sequence.
     * 
     * Approach:
     * We will iterate through all possible subarrays of the given array. For each subarray defined 
     * by its start and end indices, we will check if removing it leaves the remaining elements in a 
     * strictly increasing order. This is done by checking all elements outside the subarray and ensuring 
     * that they are in increasing order.
     *
     * Time Complexity:
     * The solution has a time complexity of O(n^3), where n is the size of the input array. 
     * This is due to three nested loops: one for selecting the start index, one for selecting the 
     * end index, and one for checking the remaining elements.
     *
     * @param nums A vector of integers representing the input array.
     * @return The count of "incremovable" subarrays.
     */
