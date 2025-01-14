//Count the Number of Square-Free Subsets

#define ll long long
#define md 1000000007
class Solution
{
public:
   int squareFreeSubsets(vector<int> &v)
   {
      ll n=v.size();
      ll a[10]={2,3,5,7,11,13,17,19,23,29};
      ll dp[n+1][1024];
      for(int i=0;i<1024;i++)
          dp[n][i]=1;
      for(ll i=n-1;i>=0;i--)
      {
          for(ll j=1023;j>=0;j--)
          {
              dp[i][j]=dp[i+1][j];
              bool ck=1;
              ll nj=j;
              ll ele=v[i];
              for(ll k=0;k<10;k++)
              {
                  while (ele%a[k]==0)
                  {
                      ele/=a[k];
                      if ((nj & 1<<k)>>k)
                      {
                          ck=0;
                          break;
                      }
                      else
                          nj=(nj | 1<<k);
                  }
              }
              if (ck)
              dp[i][j]=(dp[i][j]+dp[i+1][nj])%md;
          }
      }
      return (dp[0][0]-1+md)%md;
   }
};

/*
 * Definition:
 * The problem involves counting the number of square-free subsets in an array of integers.
 * A square-free subset is defined as a subset where no prime factor appears more than once 
 * in any of its elements.
 *
 * Approach:
 * - Use dynamic programming to keep track of valid subsets based on their prime factorization.
 * - Create a bitmask to represent which primes are present in the current subset.
 * - Iterate through each element and check its prime factors against previously used primes.
 * - Update the DP table accordingly to count valid subsets.
 *
 * Complexity:
 * - Time Complexity: O(n * m), where n is the number of elements in `v` and m is the number 
 *   of possible combinations of prime factors (1024 for up to 10 primes).
 * - Space Complexity: O(n * m), due to the DP table storing counts for subsets.
 */
