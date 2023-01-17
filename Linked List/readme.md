## 1)Reverse LL
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

## 2)Merge Two LL
        use two pointer