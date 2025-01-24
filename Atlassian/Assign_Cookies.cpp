//Assign Cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size() ;
        int n=s.size() ;
        int child=0 ; // Pointer for children
        int cookie=0;
        int childcount=0 ; // Count of content children
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(child<m && cookie<n){
            if(s[cookie++]>=g[child]){
                childcount++;
                child++; // Move to the next child
            }
        }
        return childcount;
    }
};

/*
 * Definition:
 * The problem involves distributing cookies to children based on their greed factors. 
 * Each child has a specific greed factor, and each cookie has a size. A child can 
 * be content if they receive a cookie whose size is at least equal to their greed factor.
 *
 * Approach:
 * - Sort both the greed factors and cookie sizes.
 * - Use a greedy approach to iterate through both lists and assign cookies to children 
 *   when possible, maximizing the number of content children.
 *
 * Complexity:
 * - Time Complexity: O(m log m + n log n), where m is the number of children and 
 *   n is the number of cookies due to sorting.
 * - Space Complexity: O(1), as we use a constant amount of extra space for counters.
 */
