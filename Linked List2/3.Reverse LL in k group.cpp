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
     ListNode* reverse(ListNode *head){
        ListNode *prev=NULL,*curr=head,*next=curr->next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void print(ListNode *head){
        while(head){
            cout<<head->val<<"-";
            head = head->next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ph=NULL,*ch=head,*ct=head,*nh=head->next;
        if(k==1) return head;
        while(ct){
            int i=k-1;
            while(i-- && ct){
                ct = ct->next;
            }
            if(!ct) return head;
            nh = ct->next;
            ct->next = NULL;
            
            ListNode *t = reverse(ch);
            if(ph){
                ph->next=ct;
                ch->next = nh;
                ph=ch;
                ch=nh;
                ct=nh;
            }else{
                head = ct;
                ch->next = nh;
                ph = ch;
                ch = nh;
                ct=nh;
            }
             print(head);
             cout<<endl;
            
        }
        return head;
        
    }
};