//Minimum Non-Zero Product of the Array Elements

class Solution {
public:
    long long myPow(long long base, long long exponent, long long mod) {
        if (exponent == 0) return 1;
        if (exponent == 1) return base % mod;
        
        long long tmp = myPow(base, exponent/2, mod);
        
        if (exponent % 2 == 0) { // (base ^ exponent/2) * (base ^ exponent/2)
            return (tmp * tmp) % mod;
        }
        else { // (base ^ exponent/2) * (base ^ exponent/2) * base
            tmp = tmp * tmp % mod;
            base %= mod;
            return (tmp * base) % mod;
        }
    }
    
    int minNonZeroProduct(int p) {
        long long range = pow(2, p);
        range--;
        long long mod = pow(10, 9) + 7;
        long long tmp = myPow(range-1, range/2, mod);
        return (tmp * (range%mod)) % mod;
    }
};


/*
 * Definition:
 * The problem involves calculating the minimum non-zero product of all integers 
 * from 1 to (2^p - 1), taking care of large numbers by using modular arithmetic.
 *
 * Approach:
 * - Use modular exponentiation to efficiently compute powers under a modulus.
 * - Calculate the total range as (2^p - 1) and find the product using properties 
 *   of multiplication in modular arithmetic.
 *
 * Complexity:
 * - Time Complexity: O(log n), where n is the exponent due to recursive calls in 
 *   modular exponentiation.
 * - Space Complexity: O(log n), due to recursive stack space in modular exponentiation.
 */
