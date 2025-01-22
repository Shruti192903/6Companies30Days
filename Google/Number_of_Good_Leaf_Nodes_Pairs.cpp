//Number of Good Leaf Nodes Pairs

class Solution {
public:
    int ans=0;
    vector<int> solve(TreeNode* root,int d){
        if(root==NULL) return {};
        if(root->left==NULL && root->right==NULL) return {1};
        auto l=solve(root->left,d);
        auto r=solve(root->right,d);
        for(auto ll:l){
            for(auto rr:r){
                if(ll+rr<=d) ans++;
            }
        }
        vector<int> curr;
        for(auto it:l) {
            if(1+it<=d) curr.push_back(it+1);
        }
        for(auto it:r) {
            if(1+it<=d) curr.push_back(it+1);
        }
        return curr;


    }
    int countPairs(TreeNode* root, int distance) {
        solve(root,distance);
        return ans;
    }
};

/*
 * Definition:
 * The problem involves counting pairs of leaf nodes in a binary tree such that 
 * the distance between them does not exceed a given limit. A pair of nodes is 
 * considered "good" if they are both leaf nodes and their path length is within 
 * the specified distance.
 *
 * Approach:
 * - Use a recursive depth-first search (DFS) strategy to traverse the tree.
 * - For each node, calculate distances from its leaf nodes to their parent.
 * - Count valid pairs of leaf nodes from both left and right subtrees that 
 *   meet the distance criteria.
 *
 * Complexity:
 * - Time Complexity: O(N^2) in the worst case due to nested loops for counting 
 *   pairs, where N is the number of nodes in the tree. However, in practice, 
 *   it can be more efficient depending on tree structure.
 * - Space Complexity: O(H), where H is the height of the tree due to recursion 
 *   stack space. In a skewed tree, this could be O(N).
 */
