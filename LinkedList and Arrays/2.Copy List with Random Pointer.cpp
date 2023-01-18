/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void print(Node *head){
        Node *p = head;
        while(p){
            cout<<p->val<<" ";
            if(p->random) cout<<"("<<p->random->val<<")"<<" ";
            p = p->next;
        }
        cout<<endl;
    }
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *p=head;
        while(p){
            Node *n = new Node(p->val);
            n->next = p->next;
            p->next = n;
            p = n->next;
        }
        //print(head);
        p=head;
        while(p->next->next){
           // cout<<p->val<<endl;
            if(p->random!=NULL){
                p->next->random = p->random->next;
            //cout<<p->val<<":"<<p->random->val<<";"<<endl;    
            }
            
            p = p->next->next;
        }
        if(p->random){
            p->next->random = p->random->next;
        }
        cout<<endl;
       // print(head);
        p=head;
        Node *ans=head->next,*q=ans;
        while(p->next->next){
           q=p->next;
           p->next = q->next;
           p=p->next;
           q->next = p->next;
        }
       
        p->next=NULL;
        // q=q->next;
        // q->next=NULL;
        return ans;
    }
};