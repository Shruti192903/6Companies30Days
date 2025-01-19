//Find the City With the Smallest Number of Neighbors at a Threshold Distance

#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Set distance to self as 0
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            dist[u][v] = min(dist[u][v], weight);
            dist[v][u] = min(dist[v][u], weight); // undirected
        }

        // Floyd-Warshall algorithm to find shortest paths
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int minReachableCities = numeric_limits<int>::max();
        int resultCity = -1;

        // Count reachable cities within distanceThreshold
        for (int i = 0; i < n; ++i) {
            int reachableCount = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            
            if (reachableCount <= minReachableCities) {
                minReachableCities = reachableCount;
                resultCity = i; 
            }
        }

        return resultCity; 
    }
};

/*
 * Definition:
 * The problem involves finding a city that has the smallest number of other 
 * cities reachable within a specified distance threshold. If there are multiple 
 * such cities, return the one with the highest index.
 *
 * Approach:
 * - Use Floyd-Warshall algorithm to compute shortest paths between all pairs of cities.
 * - Count how many cities are reachable from each city within the given distance threshold.
 * - Track and return the city with the minimum count of reachable cities.
 *
 * Complexity:
 * - Time Complexity: O(n^3), where n is the number of cities. This is due to 
 *   three nested loops in Floyd-Warshall algorithm.
 * - Space Complexity: O(n^2), as we maintain a distance matrix to store shortest paths.
 */
