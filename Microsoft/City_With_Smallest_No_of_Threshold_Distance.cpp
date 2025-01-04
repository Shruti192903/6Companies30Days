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

/**
     * Definition:
     * The findTheCity function determines which city has the smallest number of neighboring cities 
     * that can be reached within a specified distance threshold. If there are multiple cities with 
     * the same number of reachable neighbors, the function returns the city with the highest index.
     *
     * Approach:
     * 1. Initialize a distance matrix to represent the graph, where dist[i][j] holds the weight of 
     *    the edge between city i and city j. Set initial distances to INT_MAX, except for self-distances 
     *    which are set to 0.
     * 2. Populate the distance matrix using the provided edges. Since the graph is undirected, update 
     *    both directions for each edge.
     * 3. Apply the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities. 
     *    This involves three nested loops that update distances based on intermediate nodes.
     * 4. For each city, count how many other cities are reachable within the specified distance threshold.
     * 5. Track the city with the minimum number of reachable neighbors; in case of ties, select the city 
     *    with the highest index.
     *
     * Time Complexity:
     * The time complexity is O(n^3), where n is the number of cities. This is due to the triple nested loops 
     * in the Floyd-Warshall algorithm used to compute shortest paths.
     *
     * Space Complexity:
     * The space complexity is O(n^2) for storing distances in a 2D matrix.
**/
