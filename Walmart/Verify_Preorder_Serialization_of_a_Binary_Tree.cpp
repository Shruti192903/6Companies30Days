//Verify Preorder Serialization of a Binary Tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string curr;
        int nodes = 1;
        while (getline(ss, curr, ',')) {
            nodes--;
            if (nodes < 0){
                return false;
            } 
            if (curr != "#") {
                nodes += 2;
            }
        }
        return nodes == 0;
    }
};

/*
 * Definition:
 * The problem involves checking if a given preorder serialization of a binary tree 
 * is valid. A valid serialization means that every non-null node must have two children 
 * or be followed by nulls (#) to fill in those positions.
 *
 * Approach:
 * - Use a stringstream to parse the input string by splitting it at commas.
 * - Maintain a count of available nodes starting from 1 (the root).
 * - For each node processed:
 *   - Decrease the count of available nodes.
 *   - If the count drops below zero at any point, return false (invalid).
 *   - If the current node is not null ('#'), increase the count by 2 (for its children).
 * - Finally, check if all nodes were used up correctly by ensuring the count is zero.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the number of characters in the input string. 
 *   We process each character once.
 * - Space Complexity: O(1), as we use a constant amount of space for variables 
 *   regardless of input size.
 */
