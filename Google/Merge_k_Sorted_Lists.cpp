//Merge k Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(auto head : lists)  if(head != NULL) pq.push({head->val, head});

        while(!pq.empty()){
            ListNode* minNode = pq.top().second;
            pq.pop();
            if(minNode->next != NULL) pq.push({minNode->next->val, minNode->next});

            dummyTail->next = minNode;
            dummyTail = dummyTail->next;
        }
        return dummyHead->next;
    }
};

/*
 * Definition:
 * The problem involves merging k sorted linked lists into a single sorted linked list.
 *
 * Approach:
 * - Use a priority queue (min-heap) to efficiently retrieve the smallest head among 
 *   all current heads of the k lists.
 * - Initialize a dummy head for easier management of the merged list.
 * - Continuously extract the smallest node from the heap and add it to the merged list,
 *   pushing its next node back into the heap until all nodes are processed.
 *
 * Complexity:
 * - Time Complexity: O(N log k), where N is the total number of nodes across all lists 
 *   and k is the number of linked lists. Each insertion and extraction operation on 
 *   the heap takes O(log k).
 * - Space Complexity: O(k), as we store at most k nodes in the heap at any time.
 */
