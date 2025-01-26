//Find the Distance Value Between Two Arrays

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int m = arr1.size();
        int n = arr2.size();
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            int l = 0, r = n-1, x = arr1[i] - d, y = arr1[i] + d;
            
            while (l <= r) {
                int mid = l+ (r-l)/2;
                if (arr2[mid] < x) {
                    l = mid + 1;
                } 
                else if (arr2[mid] > y) {
                    r = mid - 1;
                } 
                else {
                    cnt++; break;
                }
            }
        }
        return m - cnt;
    }
};

/*
 * Definition:
 * The problem involves determining how many elements from one array (arr1) 
 * do not have any corresponding elements in another array (arr2) within a 
 * specified distance d.
 *
 * Approach:
 * - Sort the second array to enable binary search.
 * - For each element in the first array, use binary search to check if there 
 *   exists any element in the second array within the range [value - d, value + d].
 * - Count how many elements from the first array do not have such a match.
 *
 * Complexity:
 * - Time Complexity: O(m log n), where m is the size of arr1 and n is the size 
 *   of arr2. Sorting takes O(n log n) and each search takes O(log n).
 * - Space Complexity: O(1), as we are using only a few extra variables.
 */
