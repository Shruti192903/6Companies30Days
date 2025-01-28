//Finding consecutive integers from a Data Stream

class DataStream {
public:
    int a,k1,ct;
    DataStream(int value, int k) {
         a=value;
         k1=k;
         ct=0;
    }
    
    bool consec(int num) {
        if(num==a) ct++;
        else{ ct=0; return false;}
        if(ct>=k1) return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

/*
     * Definition:
     * This function checks if the incoming number matches the tracked value 
     * and increments the counter accordingly. If it doesn't match, it resets 
     * the counter and returns false.
     *
     * Approach:
     * - If the incoming number matches the tracked value, increment the counter.
     * - If it doesn't match, reset the counter to zero and return false.
     * - Check if the counter has reached or exceeded k; if so, return true.
     *
     * Complexity:
     * - Time Complexity: O(1), as this function performs a constant amount 
     *   of work regardless of input size.
     * - Space Complexity: O(1), as only a fixed amount of additional space 
     *   is used for counters and variables.
     */
