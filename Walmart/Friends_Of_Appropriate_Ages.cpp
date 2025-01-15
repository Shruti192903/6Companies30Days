//Friends Of Appropriate Ages

class Solution {
public:
        int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> count;
        for (int &age : ages)
            count[age]++;
        int res = 0;
        for (auto &a : count)
            for (auto &b : count)
                if (request(a.first, b.first))
                    res += a.second * (b.second - (a.first == b.first ? 1 : 0));
        return res;
    }

    bool request(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }
};

/*
 * Definition:
 * The problem involves counting the number of valid friend requests that can be sent 
 * based on specific age criteria. A person can send a friend request to another person 
 * if certain conditions regarding their ages are met.
 *
 * Approach:
 * - Use an unordered map to count how many people there are for each age.
 * - Iterate through each unique pair of ages and check if a friend request can be sent 
 *   using the `request` function.
 * - If valid, calculate the number of requests based on the counts in the map.
 *
 * Complexity:
 * - Time Complexity: O(n^2), where n is the number of unique ages. In the worst case, we 
 *   check every combination of ages in the map.
 * - Space Complexity: O(n), where n is the number of unique ages stored in the map.
 */
