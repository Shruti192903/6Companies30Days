// Kth Largest Element in a Stream

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums): k(k){
        for(int x: nums) {
            pq.push(x);
            if (pq.size()> k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size()> k) pq.pop();   
        return pq.top();      
    }
};


/*
 * Definition:
 * The problem involves maintaining the k-th largest element in a dynamic stream of integers. 
 * As new integers are added, we need to efficiently keep track of the k-th largest number.
 *
 * Approach:
 * - Use a min-heap (priority queue) to store the k largest elements seen so far.
 * - On initialization, populate the heap with the initial numbers while ensuring it 
 *   contains at most k elements.
 * - For each new number added, push it into the heap and pop the smallest element if 
 *   the size exceeds k. The top of the heap will always be the k-th largest element.
 *
 * Complexity:
 * - Time Complexity: O(N log k) for initialization where N is the number of initial numbers. 
 *   Each add operation takes O(log k).
 * - Space Complexity: O(k), as we store at most k elements in the min-heap.
 */
