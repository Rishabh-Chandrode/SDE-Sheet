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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head=new ListNode();
        ListNode *tail=head;
        ListNode *p=list1,*q=list2;
        while(p && q){
            if(p->val<q->val){
                tail->next=p;
                p=p->next;
            }else{
                tail->next=q;
                q=q->next;
            }
            tail=tail->next;
            tail->next=NULL;
        }
        while(p){
            tail->next=p;
            p=p->next;
            tail=tail->next;
            tail->next=NULL;
        }
        while(q){
            tail->next=q;
            q=q->next;
            tail=tail->next;
            tail->next=NULL;
        }
        return head->next;
    }
};