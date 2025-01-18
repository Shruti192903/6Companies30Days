//Destroying Asteroids

class Solution
{
    public:
    bool asteroidsDestroyed(int mass, vector<int>& arr)
    {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        long long m=mass;
        for (int i=0;i<n;i++)
        {
            if (arr[i]<=m)
                m+=arr[i];
            else
                return false;
        }
        return true;
    }
};

/*
 * Definition:
 * The problem involves determining whether a spaceship can destroy all incoming asteroids 
 * given its initial mass. The spaceship can destroy an asteroid if its mass is greater than 
 * or equal to the mass of the asteroid. After destroying an asteroid, its mass is added to 
 * the spaceship's mass.
 *
 * Approach:
 * - Sort the array of asteroid masses to handle them in increasing order.
 * - Iterate through each asteroid and check if it can be destroyed with the current mass.
 * - If it can be destroyed, update the spaceship's mass; if not, return false.
 *
 * Complexity:
 * - Time Complexity: O(n log n), where n is the number of asteroids. This is due to sorting 
 *   the array of masses.
 * - Space Complexity: O(1), as we are using a constant amount of space for variables.
 */
