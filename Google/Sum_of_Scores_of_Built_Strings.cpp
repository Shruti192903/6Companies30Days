//Sum of Scores of Built Strings

#define MAXN 100010

class Solution {
	int Z[MAXN];

	void getZarr(string str, int Z[])
	{
		int n = str.length();
		int L, R, k;

		Z[0] = n;

		L = R = 0;
		for (int i = 1; i < n; ++i)
		{

			if (i > R)
			{
				L = R = i;

				while (R < n && str[R - L] == str[R])
					R++;
				Z[i] = R - L;
				R--;
			}
			else
			{

				k = i - L;

				if (Z[k] < R - i + 1)
					Z[i] = Z[k];

				else
				{
					L = i;
					while (R < n && str[R - L] == str[R])
						R++;
					Z[i] = R - L;
					R--;
				}
			}
		}
	}

public:
	long long sumScores(string s) {
		long long n = s.length(), i, j, k, ans = 0;
		getZarr(s, Z);
		for (i = 0; i < n; i++)
    {
      ans += Z[i];
    }
		return ans;
	}
};
/*
 * Definition:
 * The problem involves calculating scores for substrings of a given string 
 * using its Z-array. Each entry in the Z-array represents how many characters 
 * match between a substring starting at that position and the prefix of 
 * the string.
 *
 * Approach:
 * - Use a helper function to compute the Z-array using an efficient algorithm 
 *   that runs in O(n) time.
 * - Sum all values in the Z-array to get the total score.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the length of the string. The algorithm 
 *   processes each character a limited number of times.
 * - Space Complexity: O(n), used for storing the Z-array.
 */
