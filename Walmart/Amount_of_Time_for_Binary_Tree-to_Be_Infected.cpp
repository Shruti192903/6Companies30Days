//Amount of Time for Binary Tree to Be Infected

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
using namespace std;
class Solution {
public:
    int result;

    int amountOfTime(TreeNode* root, int start) {
        DFS(root, start);
        return result;
    }

    int DFS(TreeNode* node, int start){
        if(node == NULL) return 0;

        int leftDepth = DFS(node->left, start);
        int rightDepth = DFS(node->right, start);

        if(node->val == start){
            result = max(leftDepth, rightDepth);
            return -1;
        }
        else if(leftDepth >= 0 && rightDepth >= 0)
            return max(leftDepth, rightDepth)+1;
        
        result = max(result, abs(leftDepth - rightDepth));
        return min(leftDepth, rightDepth) - 1;
    }
};


/*
 * Definition:
 * The problem involves calculating the amount of time it takes for all nodes in a binary tree 
 * to be affected by a signal starting from a specific node. The signal spreads to adjacent nodes 
 * in each step.
 *
 * Approach:
 * - Perform a Depth-First Search (DFS) traversal of the binary tree.
 * - When we reach the starting node, we calculate how deep we can go into its left and right subtrees.
 * - We track how long it takes for the signal to reach all nodes by comparing depths from both sides.
 * - The maximum time taken is updated as we backtrack through the tree.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the number of nodes in the binary tree. We visit each node once.
 * - Space Complexity: O(h), where h is the height of the tree due to recursive stack space used during DFS.
 */
