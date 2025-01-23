//Count Subtrees With Max Distance Between Cities

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX/2-1));
        for (auto e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            graph[u][v] = graph[v][u] = 1;
        }
        
        //floyed-warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        
        vector<int> res(n-1, 0);
        

        for (int sub = 0; sub < (1 << n); sub++) {
            int nodes = __builtin_popcount(sub);
            int edges = 0;
            int dist = 0;
            for (int i = 0; i < n; i++)
                if (sub & (1 << i)) {
                    for (int j = i + 1; j < n; j++) 
                        if (sub & (1 << j)) {
                            edges += graph[i][j] == 1;
                            dist = max(dist, graph[i][j]);
                    }
            }
            if (edges == nodes - 1 && dist > 0) {
                res[dist - 1]++;
            }
        }
        
        return res;
    }
};

/*
 * Definition:
 * The problem involves counting the number of connected subgraphs in an undirected 
 * graph that have a specific diameter. A subgraph's diameter is defined as the 
 * longest shortest path between any two nodes within that subgraph.
 *
 * Approach:
 * - Use Floyd-Warshall algorithm to compute shortest paths between all pairs of nodes.
 * - Iterate through all possible subsets of nodes to determine valid connected subgraphs.
 * - For each valid subgraph, check its diameter and update counts accordingly.
 *
 * Complexity:
 * - Time Complexity: O(2^N * N^2), where N is the number of nodes. The outer loop 
 *   iterates through all subsets (2^N), while inner loops compute edges and distances 
 *   which takes O(N^2).
 * - Space Complexity: O(N^2), used for storing the adjacency matrix representation 
 *   of shortest paths.
 */
