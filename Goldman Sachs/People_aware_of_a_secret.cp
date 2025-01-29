//People aware of a secret

class Solution {
int dp[1001];
#define mod 1000000007
public:
    int solve(int idx,int d,int f,int n){
        if(idx+d>n)return 1;
        if(dp[idx]!=-1)return dp[idx];
        int ans=1;
        for(int i=idx+d;i <= min(n,idx+f);i++){
            if(i==idx+f){
                ans-=1;
                break;
            }
            ans= (ans%mod + solve(i,d,f,n)%mod)%mod;
        }
        return dp[idx]=ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
       return solve(1,delay,forget,n); 
    }
};

/* Definition:
 * This function counts how many times each number appears in the input array 
 * and returns a list of these counts.
 *
 * Approach:
 * - Use an unordered map to store the frequency of each element.
 * - Iterate through the input array and update the frequency in the map.
 * - Convert the map into a vector of pairs for output.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the number of elements in the input array. 
 *   Each element is processed once.
 * - Space Complexity: O(m), where m is the number of unique elements in the array. 
 *   This space is used to store frequencies in the unordered map.
 */
