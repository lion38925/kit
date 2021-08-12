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
    int getDecimalValue(ListNode* head) {
        
        int i,n=0,j=0;
        
        while(head!=NULL){
            n=n|head->val;      // here we are taking or of numbers
            n=n<<1;             // here we are shifting to the left
            head = head->next;
        }
        return n>>1;
        
    }
};