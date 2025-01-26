//The Number of Good Subsets

class Solution {
public:
    int mod=1e9+7;
    vector<int>prime;
    int mp[45];
    long long dp[31][1<<12];
    int find(int n)
    {
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    long long find(int value,int mask)
    {
        if(value>30)
        {
            return (mask>0);
        }
        if(dp[value][mask]!=-1)
        {
            return dp[value][mask]%mod;
        }
        int new_mask=0;
        long long product=1;
        for(int i=0;i<prime.size();i++)
        {
            if((value%prime[i])==0)
            {
                product*=prime[i];
                new_mask|=(1<<i);
            }
        }
        long long ans=find(value+1,mask);
        if(product==value&&mp[value]&&((mask&new_mask)==0))
        {
            ans+=(find(value+1,mask|new_mask)*mp[value]);
        }
        return dp[value][mask]=ans%mod;
    }
    int numberOfGoodSubsets(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        for(int i=2;i<=30;i++)
        {
            if(find(i))
            {
                prime.push_back(i);
            }
        }
        for(auto it:nums)
        {
            mp[it]++;
        }
        long long val=find(2,0)%mod;
        long one=1;
        for(int i=0;i<mp[1];i++)
        {
            one=(one*2)%mod;
        }
        val=(val*one)%mod;
        return val;
    }
};

/*
 * Definition:
 * The problem involves calculating the number of good subsets from an 
 * integer array where a subset is considered good if every element can 
 * be represented as a product of distinct prime factors.
 *
 * Approach:
 * - Use dynamic programming to count valid subsets recursively while 
 *   keeping track of used primes via bitmasking.
 * - Precompute all primes up to a certain limit and use their properties 
 *   to determine valid products.
 *
 * Complexity:
 * - Time Complexity: O(2^p), where p is the number of distinct primes 
 *   considered. The recursive calls depend on the size of the input 
 *   and the number of valid combinations.
 * - Space Complexity: O(31*2^12), due to DP storage and bitmasking.
 */
