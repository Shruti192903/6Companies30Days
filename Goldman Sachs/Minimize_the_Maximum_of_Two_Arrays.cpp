//Minimize the Maximum of Two Arrays

#define ll long long
class Solution {
private:
    int gcd(int a, int b) {
        if (!b) return a;
        return gcd(b, a % b);
    }
    int lcm(ll a, ll b) {
        ll temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }
public:
    int minimizeSet(int divisor1, int divisor2, int uc1, int uc2) {
        int l = 1, r = INT_MAX, LCM = lcm(divisor1, divisor2);
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int a = mid / divisor1, b = mid / divisor2;
            if (uc1 <= mid - a && uc2 <= mid - b && uc1 + uc2 <= (mid - (mid / LCM))) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};


/*
 * Definition:
 * The problem involves finding the smallest positive integer such that 
 * certain constraints regarding divisibility by two given numbers and 
 * upper counts are satisfied.
 *
 * Approach:
 * - Use binary search to efficiently find the minimum integer that meets 
 *   the conditions based on how many numbers are divisible by each divisor 
 *   within the range being searched.
 *
 * Complexity:
 * - Time Complexity: O(log(INT_MAX)), since we are performing binary search 
 *   over possible values up to INT_MAX.
 * - Space Complexity: O(1), as we are using only a constant amount of space 
 *   for variables.
 */
