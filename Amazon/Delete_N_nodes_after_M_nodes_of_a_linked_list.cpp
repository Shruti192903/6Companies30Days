//Delete N nodes after M nodes of a linked list
class Solution{
public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* node = head;
        while(node!=nullptr)
        {
            Node* prev = nullptr;
            // Skip m nodes
            for(size_t id=0; id<m && node!=nullptr; id++)
            {
                prev = node; //Keeping track of last node before skipping
                node = node->next;
            }
            
            // Delete n nodes
            for(size_t id=0; id<n && node!=nullptr; id++)
            {
                Node* temp = node;
                node = node->next;
                delete temp; // Delete the current node
            }
            prev->next = node;
        }
        return head;
    }
};

/**
     * Definition:
     * The linkdelete function modifies a linked list by deleting a specified 
     * number of nodes (n) after skipping a specified number of nodes (m).
     *
     * Approach:
     * 1. Initialize a pointer to traverse the list.
     * 2. Use a loop to skip m nodes and then delete n nodes.
     * 3. Link the last skipped node to the next valid node.
     *
     * Time Complexity: O(k), where k is the total number of nodes in the list.
     * Space Complexity: O(1), since we use a constant amount of extra space.
 **/
