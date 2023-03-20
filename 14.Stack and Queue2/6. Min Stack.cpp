class MinStack {
public:
    struct Node{
        Node *prev;
        int key;
        int min;
        Node *next;
    };
    Node *head;
    MinStack() {
        head = NULL;
    }
    
    void push(int val) {
        Node *newnode = new Node();
        newnode->key = val;

        if(!head){
            head = newnode;
            head->prev = NULL;
            head->next = NULL;
            head->min = val;
            return;
        }
        head->next = newnode;
        newnode->prev = head;
        if(head->min > newnode->key){
            newnode->min = newnode->key;
        }else{
            newnode->min = head->min;
        }
        head = newnode;
        return ;
    }
    
    void pop() {
        Node *n = head;
        head = head->prev;
        if(!head) {
            delete n;
            return;
        }
        head->next = NULL;
        n->prev = NULL;
        delete n;
        return;
    }
    
    int top() {
        if(head) return head->key;
        return -1;
    }
    
    int getMin() {
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */