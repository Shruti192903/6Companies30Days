//Tree Serialization and Deserialization

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    string serialize(TreeNode* root) {
         if(!root)
            return "null,";
    // Pre-order traversal: node value, left subtree, right subtree
      string s=to_string(root->val)+",";
      string s1=serialize(root->left);
      string s2=serialize(root->right);
      return s+s1+s2;
    }
    
    TreeNode* makeTree(queue<string> & q)
    {
        string s=q.front();
        q.pop();
        if(s=="null")
            return NULL;
        TreeNode* t=new TreeNode(stoi(s));
        t->left=makeTree(q);
        t->right=makeTree(q);
        return t;
        
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s="";
        for(char c:data)
        {
            if(c==',')
            {
                q.push(s);
                s="";
            }
            else
                s+=c;
        }
        return makeTree(q);
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


/*
 * Definition:
 * The Codec class provides methods to serialize and deserialize a binary tree.
 * Serialization converts a binary tree into a string format, while deserialization
 * reconstructs the tree from that string.
 *
 * Approach:
 * - The `serialize` function performs a pre-order traversal of the tree.
 *   It appends the value of each node to a string, using "null" for null nodes,
 *   and separates values with commas.
 * - The `deserialize` function converts the serialized string back into a binary tree.
 *   It splits the string by commas and uses a queue to facilitate reconstruction.
 * - The `makeTree` function recursively constructs the tree by dequeuing values
 *   and creating nodes as needed.
 *
 * Complexity:
 * - Time Complexity: O(n), where n is the number of nodes in the tree. Each node is 
 *   visited once during serialization and deserialization.
 * - Space Complexity: O(n) for storing the serialized string and for the queue used 
 *   during deserialization.
 */
