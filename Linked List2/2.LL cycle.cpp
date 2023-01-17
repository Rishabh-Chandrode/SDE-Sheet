/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *p=head,*q=head->next;
        while(p!=q){
            if(p==NULL || q==NULL || q->next==NULL){
                return false;
            }
            p=p->next;
            q=q->next->next;
        }
        return true;
    }
};