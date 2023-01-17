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
    ListNode* add(ListNode *l1,ListNode *l2){
        ListNode *p=l1,*q=l2;
        ListNode *head=new ListNode();
        ListNode *tail=head;
        bool c=0;
        while(p&&q){
            int sum=p->val+q->val+c;
            if(sum>9){
                sum=sum%10;
                c=1;
            }else{
                c=0;
            }
            ListNode *n=new ListNode(sum);
            tail->next = n;
            tail=tail->next;
            p=p->next;
            q=q->next;

        }
        while(p){
            int sum=p->val+c;
            if(sum>9){
                sum=sum%10;
                c=1;
            }else{
                c=0;
            }
            ListNode *n=new ListNode(sum);
            tail->next = n;
            tail=tail->next;
            p=p->next;

        }
        while(q){
            int sum=q->val+c;
            if(sum>9){
                sum=sum%10;
                c=1;
            }else{
                c=0;
            }
            ListNode *n=new ListNode(sum);
            tail->next = n;
            tail=tail->next;
            q=q->next;
        }
        if(c){
            ListNode *n=new ListNode(1);
            tail->next = n;
            tail=tail->next;

        }
        return head->next;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p;
        p = add(l1,l2);
        return p;
    }
};