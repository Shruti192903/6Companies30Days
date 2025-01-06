//Longest Mountain in Array

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to find the length of the longest mountain in the array
    int longestMountain(vector<int>& A) {
        int n = A.size(); 
        int max_length = 0;

        // Check if the size of A is less than 3
        if (n < 3) return 0;

        for (int i = 1; i < n - 1; i++) {
            // Check for peak condition
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) {//greater than its neighbors
                int start_root = i;
                int end_root = i;
                while (start_root > 0 && A[start_root] > A[start_root - 1]) {
                    start_root--;
                }
                while (end_root < n - 1 && A[end_root] > A[end_root + 1]) {
                    end_root++;
                }

                max_length = max(max_length, end_root - start_root + 1);

                // Move i to end_root to skip over this mountain
                i = end_root;
            }
        }
        return max_length; 
    }
};

ic:
    /**
     * Definition:
     * The longestMountain function finds the length of the longest mountain 
     * in an array of integers. A mountain is defined as a sequence of numbers 
     * that first strictly increases and then strictly decreases.
     *
     * Approach:
     * 1. Initialize a variable to store the maximum length of any mountain found.
     * 2. Check if the size of the input array is less than 3; if so, return 0 
     *    since a mountain cannot exist with fewer than three elements.
     * 3. Iterate through the array starting from index 1 to n-2 (to avoid out-of-bounds).
     * 4. For each element, check if it is a peak (greater than its neighbors).
     * 5. If a peak is found, expand to the left and right to find the full extent 
     *    of the mountain.
     * 6. Calculate the length of the mountain and update the maximum length if needed.
     * 7. Skip over indices that are part of this mountain to avoid counting them again.
     * 8. Return the maximum length found after checking all possible peaks.
     *
     * Time Complexity: O(n), where n is the number of elements in the array.
     * Space Complexity: O(1), since we use only a fixed amount of extra space.
     *
     * @param A A vector of integers representing the input array.
     * @return The length of the longest mountain in the array.
    **/
   
