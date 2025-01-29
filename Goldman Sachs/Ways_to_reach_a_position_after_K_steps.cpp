//Ways to reach a position after K steps

class Solution {
public:
    int dp(int currPos,int &endPos, int remainingSteps,vector <vector <int>> &cache){
        if(currPos==endPos && remainingSteps==0){
            return 1;
        }
        
        if(remainingSteps<=0){
            return 0;
        }
        
        int &ans=cache[currPos][remainingSteps];
        
        if(ans!=-1){
            return ans;
        }
        
        return ans=(dp(currPos+1,endPos,remainingSteps-1,cache)+dp(currPos-1,endPos,remainingSteps-1,cache))%1000000007;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        startPos+=1200;
        endPos+=1200;
        
        vector <vector <int>> cache(4000,vector <int> (k+1,-1));
        return dp(startPos,endPos,k,cache);
    }
};

/* Definition:
     * This function uses recursion with memoization to count the distinct 
     * ways to reach a specific position in a given number of steps.
     *
     * Approach:
     * - If the current position equals the end position and no remaining steps are left, 
     *   return 1 (a valid way).
     * - If there are no remaining steps but not at the end position, return 0 (invalid).
     * - Use memoization to store previously computed results for specific positions and steps 
     *   to avoid redundant calculations.
     * - Recursively call the function for both possible moves (left and right) and sum their results.
     *
     * Complexity:
     * - Time Complexity: O(k), where k is the number of steps. Each state (position and steps) 
     *   is computed once due to memoization.
     * - Space Complexity: O(n), where n is the size of the cache (in this case, 4000 x (k + 1)).
*/
