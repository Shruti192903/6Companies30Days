// Wiggle Sort II

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(std::vector<int>& nums) {
        int arraySize = nums.size();
        vector<int> sortedArray(nums);
        sort(sortedArray.begin(), sortedArray.end());
        
        int currentIndex = arraySize - 1;
        int smallIndex = 0;
        int largeIndex = (arraySize + 1) / 2;

        while (currentIndex >= 0) {
            if (currentIndex % 2 == 1) {
                nums[currentIndex] = sortedArray[largeIndex];
                largeIndex++;
            } else {
                nums[currentIndex] = sortedArray[smallIndex];
                smallIndex++;
            }
            currentIndex--;
        }
    }
};


/**
     * Definition:
     * Wiggle sort is a rearrangement of an array such that for every 
     * i (0 <= i < nums.size() - 1), the following condition holds:
     * nums[0] < nums[1] > nums[2] < nums[3] > nums[4] ...
     * This means that the elements at even indices should be less than 
     * their subsequent odd indices, and the elements at odd indices 
     * should be greater than their preceding even indices.
     *
     * Approach:
     * 1. Create a copy of the original array and sort it.
     * 2. Use two pointers: one for the smaller half (smallIndex) and 
     *    another for the larger half (largeIndex) of the sorted array.
     * 3. Fill the original array in a wiggle manner by alternating 
     *    between larger and smaller elements based on the current index.
     *
     * Time Complexity:
     * The time complexity is O(n log n) due to the sorting step, where n 
     * is the size of the input array. The subsequent filling of the array 
     * operates in O(n), making sorting the dominant factor.
     **/
