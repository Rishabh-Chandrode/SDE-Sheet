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
    void deleteNode(ListNode* node) {
        ListNode *p=node,*q;
        while(p->next){
            p->val=p->next->val;
            q=p;
            p=p->next;
        }
        q->next=NULL;


    }
};