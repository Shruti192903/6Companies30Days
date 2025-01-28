//Combination Sum

class Solution {
public:   
    void helper(int i, int t, vector<int>& sol, vector<vector<int>>& ans,int k){
            if(t==0 and k==0){
                ans.push_back(sol);
                return;
            }
            if(k<0 or t<0){
                return ;
            }

            if(i==10) return;

            helper(i+1,t,sol,ans,k);
            sol.push_back(i);
            helper(i+1,t-i,sol,ans,k-1);
            sol.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
             vector<vector<int>> ans;
             vector<int> sol;
                helper(1,n,sol,ans,k);
                  return ans;
    }

};

/*
 * Definition:
 * The problem involves finding all unique combinations of k numbers 
 * from the range [1-9] that add up to a given number n. Each 
 * combination must consist of distinct numbers.
 *
 * Approach:
 * - Use a backtracking approach where we explore both including 
 *   and excluding each number from 1 to 9.
 * - Track the current combination and only add it to results 
 *   when it meets the criteria (sum equals n and exactly k numbers).
 *
 * Complexity:
 * - Time Complexity: O(2^n), where n is the number of choices 
 *   (in this case, at most 9). The recursion explores all subsets.
 * - Space Complexity: O(n), for storing the current combination 
 *   and results.
 */
