/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// in this node there is no head pointer given, only node pointer is givem directly

// so what we will do it copy the next element value to the current node and 
// then will make it to point to next next of it
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        node->val = node->next->val;
        
        node->next=node->next->next;
    
        
    }
};