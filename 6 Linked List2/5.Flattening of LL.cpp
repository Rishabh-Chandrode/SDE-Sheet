
/*  Function which returns the  root of 
    the flattened linked list. */
    Node* merge(Node *l1,Node *l2){
        Node *p=l1,*q=l2;
        Node *head = new Node(-1);
        Node *tail = head;
        while(p && q){
            if(p->data < q->data){
                tail->bottom = p;
                p = p->bottom;
            }else{
                tail->bottom = q;
                q=q->bottom;
            }
            tail = tail->bottom;
        }
        while(p){
            tail->bottom = p;
            p = p->bottom;
            tail = tail->bottom;
        }
        while(q){
            tail->bottom = q;
            q=q->bottom;
            tail = tail->bottom;
        }
        return head->bottom;
    }
    
Node *flatten(Node *root)
{
   // Your code here
   if(!root || !root->next) return root;
   Node *nextlist=root->next;
   while(nextlist){
       root=merge(root,nextlist);
       nextlist=nextlist->next;
   }
   return root;
}