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
        int count=0;
        ListNode *p=head;
        while(p){
            count++;
            p=p->next;
        }
        if(count==n){
            return head->next;
        }
        count-=n;
        p=head;
        while(--count){
            p=p->next;
        }
        //cout<<p->val<<endl;
        if(n==1) p->next =NULL;
        else p->next = p->next->next;
        return head;
    }
};