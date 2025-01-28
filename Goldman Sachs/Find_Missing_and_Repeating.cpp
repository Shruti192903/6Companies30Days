//Find Missing and Repeating
class Solution{
vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans(2); // To store the repeated and missing numbers
        int n = arr.size();
        int i = 0;
    
        while (i < n) {
            if (arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            } else {
                i++;
            }
        }
    
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                ans[0] = arr[i];    
                ans[1] = i + 1;    
            }
        }
    
        return ans;
    }
};


/*
     * Definition:
     * This function finds one number that appears twice and another number 
     * that is missing from an array containing numbers from 1 to n.
     *
     * Approach:
     * - Use a cyclic sort approach where we place each number at its correct 
     *   index (i.e., arr[i] should be at index arr[i] - 1).
     * - After sorting, iterate through the array to identify the repeated 
     *   number (the one that is not in its correct position) and the missing 
     *   number (the index that does not have the expected value).
     *
     * Complexity:
     * - Time Complexity: O(n), where n is the size of the array. Each element 
     *   is processed at most twice.
     * - Space Complexity: O(1), as we are using only a constant amount of space.
  */
