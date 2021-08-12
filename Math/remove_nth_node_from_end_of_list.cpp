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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int i,j,k,l;
        l=n;
        ListNode* curr = head;
        while(curr!=NULL&&l>0){
            curr=curr->next;
            l--;
        }
        
        ListNode* temp = head;
         if(curr==NULL){            // this condition tells that we have reached the end of the list and the node to be removed
                                    // is the head one
            head=head->next;
             return head;
         }
        
        while(curr->next!=NULL&&temp!=NULL){
            curr=curr->next;
            temp=temp->next;
        }
        
        temp->next=temp->next->next;
        return head;
        
    }
};