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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        if(k==0) return head;
        int count=1;
        ListNode *p=head;
        while(p->next){
            p=p->next;
            count++;
        }
        p->next = head;
        if(k>=count) k=(k%count);
       // cout<<count<<" "<<k;
        p=head;
        count = count - k - 1;
        while(count--){
            p = p->next;
        }
        ListNode *ans = p->next;
        p->next = NULL;
        return ans;
    }
};