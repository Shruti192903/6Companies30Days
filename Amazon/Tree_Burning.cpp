//Tree Burning

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
class Solution {
public:
    pair<int,int> getPath(TreeNode *root, int start, int &result) {
        if(!root) {
            return {0,0};
        }

        pair<int,int> left = getPath(root->left,start,result);
        pair<int,int> right = getPath(root->right,start,result);

        if(root->val == start) {
            result = max(left.second,right.second);
            return {1,1};
        } else if(left.first == 1) {
            result = max(result,left.second+right.second);
            return {1,left.second+1};
        } else if(right.first == 1) {
            result = max(result,left.second+right.second);
            return {1,right.second+1};
        } else {
            return {0, max(left.second,right.second) + 1};
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        int result = 0;
        getPath(root,start, result);
        return result;
    }
};

/*
     * Definition:
     * The problem requires calculating the amount of time it takes for a fire to spread
     * through a binary tree starting from a specified node. The fire spreads to adjacent nodes
     * every minute. The goal is to determine how many minutes it takes until all nodes are affected.
     *
     * Approach:
     * - Use a recursive function `getPath` that traverses the tree and returns:
     *   1. A flag indicating whether the current node is the starting node.
     *   2. The maximum depth of the subtree affected by the fire.
     * - If the current node matches the starting node, we set the result to the maximum depth of its children.
     * - If one of the children is on fire (returns flag 1), we calculate the time taken for the fire to spread 
     *   to its sibling and update the result accordingly.
     * - Finally, we return the depth of the current node's subtree affected by fire.
     *
     * Complexity:
     * - Time Complexity: O(n), where n is the number of nodes in the binary tree. We visit each node once.
     * - Space Complexity: O(h), where h is the height of the tree due to recursion stack space.
     */
