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
        if(!head) return head;
        ListNode *prev=NULL,*curr=head,*next=head->next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
  
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
       ListNode *slow=head,*fast=head->next;
       while(fast && fast->next){
           slow=slow->next;
           fast=fast->next->next;
       }
       ListNode *h2=slow->next;
       slow->next=NULL;
       h2 = reverse(h2);
       slow->next=h2;
       slow=slow->next;
       fast=head;
       while(fast && slow){
           if(fast->val != slow->val){
               cout<<"hello";
               return false;
           }
           
           fast=fast->next;
           slow=slow->next;
       }
       
       return true;
    }
};