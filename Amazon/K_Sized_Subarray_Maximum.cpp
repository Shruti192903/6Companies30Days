//K Sized Subarray Maximum

class Solution{
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> res;
        deque<int> q;
        int n = arr.size();
        int i;
        for(i=0;i<k;i++)
        {
            while(!q.empty() && arr[i] >= q.front())
                q.pop_front();
            q.push_back(i);
        }
        for(;i<n;i++)
        {
            res.push_back(arr[q.front()]);
            if(!q.empty() && q.front() <= (i-k))
                q.pop_front();
            while(!q.empty() && arr[i] >= q.back())
                q.pop_back();
            q.push_back(i);
        }
        res.push_back(arr[q.back()]);
        return res;
    }
};

 /**
     * Definition:
     * The maxOfSubarrays function finds the maximum value in each contiguous 
     * subarray of size k from the given vector of integers. The result is 
     * returned as a vector of integers.
     *
     * Approach:
     * 1. Initialize a result vector `res` to store the maximum values and 
     *    a deque `q` to keep track of indices of array elements.
     * 2. Process the first k elements:
     *    - For each element, remove indices from the front of the deque 
     *      if they are smaller than or equal to the current element, as they 
     *      cannot be part of the maximum for any future subarrays.
     *    - Add the current index to the back of the deque.
     * 3. For the remaining elements in the array:
     *    - Push the maximum for the previous window (front of deque) into `res`.
     *    - Remove indices from the front if they are out of the current window.
     *    - Again, remove indices from the back while they are smaller than 
     *      or equal to the current element.
     *    - Add the current index to the back of the deque.
     * 4. After processing all elements, add the maximum for the last window
     *    to `res`.
     * 5. Return `res`, which contains the maximum values for each subarray of size k.
     *
     * Time Complexity: O(n), where n is the number of elements in arr. 
     *                 Each element is added and removed from the deque at most once.
     * Space Complexity: O(k), as we store at most k indices in the deque at any time.
   **/
