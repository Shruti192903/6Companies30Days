//Maximum Product After K Increments

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod=pow(10,9)+7;
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k>0){
            int x=pq.top();
            pq.pop();
            x=x+1;
            pq.push(x);
            k--;
        }
        long long int ans=1;
        while(pq.size()>0){
            int x=pq.top();
            pq.pop();
            ans=(ans*x)%mod;
        }
        return ans;
    }
};

/*
 * Definition:
 * The problem involves maximizing the product of an array after performing 
 * a specified number of increments on its elements. Each increment can only 
 * be applied to one element at a time.
 *
 * Approach:
 * - Use a min-heap (priority queue) to efficiently access and increment 
 *   the smallest element in the array.
 * - Perform k increments by continually extracting the smallest element, 
 *   incrementing it, and pushing it back into the heap.
 * - After all increments are done, calculate the product of all elements 
 *   in the heap, taking care to apply modulo at each step to prevent overflow.
 *
 * Complexity:
 * - Time Complexity: O(n + k log n), where n is the number of elements in 
 *   nums. We push all elements into the heap and perform k operations on it.
 * - Space Complexity: O(n), as we store all elements in a priority queue.
 */
