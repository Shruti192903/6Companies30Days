//Maximum Sum BST

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
    class Condition {
    public:
        int sum;
        int min_n;
        int max_n;
        bool isBst;

        Condition()
        {
            sum = 0;
            min_n = INT_MAX;
            max_n = INT_MIN;
            isBst = true;
        }
    };

    Condition check(TreeNode* root, int& ans) 
    {
        if (root == NULL) {
            return Condition();  
        }

        Condition left = check(root->left, ans);
        Condition right = check(root->right, ans);

        Condition current;
        
        if (left.isBst && right.isBst && left.max_n < root->val && root->val < right.min_n) 
        {
            current.isBst = true;
            current.sum = left.sum + right.sum + root->val;
            current.min_n = min(left.min_n, root->val);
            current.max_n = max(right.max_n, root->val);

            ans = max(ans, current.sum);
        } 
        else 
        {
            current.isBst = false;
        }

        return current;
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;

        check(root, ans);

        return ans;
    }
};

/Based on your request, here is a C++ code file that includes definitions, approaches, and complexity analyses formatted as comments. This example will illustrate the use of comments in a C++ program while implementing a simple algorithm.
C++ Code Example with Definitions, Approach, and Complexity Analysis
cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * Function to count the frequency of elements in an array.
 *
 * @param nums: A vector of integers representing the input array.
 * @return A vector of pairs where each pair contains an element and its frequency.
 *
 * Definition:
 * This function counts how many times each number appears in the input array 
 * and returns a list of these counts.
 *
 * Approach:
 * - Use an unordered map to store the frequency of each element.
 * - Iterate through the input array and update the frequency in the map.
 * - Convert the map into a vector of pairs for output.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the number of elements in the input array. 
 *   Each element is processed once.
 * - Space Complexity: O(m), where m is the number of unique elements in the array. 
 *   This space is used to store frequencies in the unordered map.
 */
