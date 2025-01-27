//Employee Priority Systems

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        
        int n = access_times.size();
        sort(access_times.begin() , access_times.end());

        vector<string>ans;
        unordered_map<string , int>mp;
        for(int i = 0; i < n - 2; i++){
            if(mp.find(access_times[i][0]) == mp.end() &&
             access_times[i][0] == access_times[i + 2][0]){
                // calculate time for access_times[i][1]
                int t1 = stoi(access_times[i][1]);

                // calculate time for access_times[i + 2][1]
                int t2 = stoi(access_times[i + 2][1]);

                if(t2 - t1 < 100){
                  i++;
                  ans.push_back(access_times[i][0]);
                  mp[access_times[i][0]]++;
                } 
            }
        }
       return ans;
    }
};


/*
 * Definition:
 * The problem involves identifying employees who have accessed a system 
 * multiple times within a short time frame (less than 100 seconds).
 *
 * Approach:
 * - Sort the access records based on employee names and timestamps.
 * - Use a sliding window approach to check for each employee's third 
 *   access record and see if it occurs within 100 seconds of their first.
 *
 * Complexity:
 * - Time Complexity: O(n log n), where n is the number of access records 
 *   due to sorting. The subsequent iteration is O(n).
 * - Space Complexity: O(m), where m is the number of unique employees 
 *   in the map.
 */
