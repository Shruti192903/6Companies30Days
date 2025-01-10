//Count ways to Nth stair
class Solution {
public:
    int waysToReachStair(int k) {
        int result = 0;
        for (int op2 = 1, op2_sum = 1; op2_sum - k <= op2; op2++, op2_sum *= 2) {
            result += C(op2, op2_sum - k);
        }
        return result;
    }
    
    int C(int a, int b) {
        if (b > a || b < 0) {
            return 0;
        }
        
        long long result = 1;
        for (int i = a, j = 1; j <= b; i--, j++) {
            result *= i;
            result /= j;
        }
        return result;
    }
};

/*
 * Definition:
 * The problem involves calculating the number of distinct ways to reach the k-th stair
 * using a combination of operations. The operations allow for moving up by 1 or 2 stairs,
 * and the goal is to find how many combinations of these operations can result in exactly k stairs.
 *
 * Approach:
 * - Use a loop to iterate over possible numbers of 2-step operations (`op2`).
 * - For each `op2`, calculate `op2_sum`, which represents the total steps taken if `op2` 
 *   two-step operations are used.
 * - The difference between `op2_sum` and `k` gives the number of 1-step operations needed.
 * - Use the combinatorial function `C` to calculate how many ways we can arrange 
 *   `op2` two-step operations and the required number of 1-step operations.
 * - Sum these values to get the total number of ways to reach stair `k`.
 *
 * Complexity:
 * - Time Complexity: O(k), where k is the input value. This is because we iterate 
 *   up to k in the worst case when calculating combinations.
 * - Space Complexity: O(1), as we only use a constant amount of space for variables 
 *   regardless of input size.
 */
