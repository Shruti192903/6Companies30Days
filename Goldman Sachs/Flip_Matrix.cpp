//Flip Matrix

class Solution {
public:
    int n,m;
    int i = 0;
    int j = 0; 

    Solution(int m, int n) {
        this->n = n;
        this->m = m;
    }
    
    vector<int> flip() {
        int I = i;
        int  J = j;
        if(j + 1 < n) {
            j++; 
        }
        else if(i + 1 < m){ // switch to next row and first col
            i++;
            j = 0;
        }
        else{
            i = 0; // point back to first row
            j = 0; // point back to first col
        } 
        //reset and continue to cycle again
        return {I,J};
    }
    void reset() {
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */


 /**
     * Definition:
     * This function uses a sliding window technique to maintain a count of 
     * occurrences of each number in the current window. It adjusts the window 
     * size based on the condition that no number exceeds k occurrences.
     *
     * Approach:
     * - Use two pointers to create a sliding window.
     * - Maintain a hash map to count occurrences of each number within the window.
     * - Expand the right pointer to include new elements and contract the left pointer 
     *   when the condition is violated (i.e., any number exceeds k occurrences).
     *
     * Complexity:
     * - Time Complexity: O(n), where n is the length of nums. Each element is processed 
     *   at most twice (once by each pointer).
     * - Space Complexity: O(m), where m is the number of unique elements in nums that 
     *   are counted in the hash map.
     */
