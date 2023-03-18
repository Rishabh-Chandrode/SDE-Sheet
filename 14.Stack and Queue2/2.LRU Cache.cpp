class LRUCache {
public:
    struct Node{
        Node *prev;
        int key;
        int value;
        Node *next;
    };
    unordered_map<int,Node*> m;
    int limit;
    Node *head = new Node();
    Node *tail = new Node();
    LRUCache(int capacity) {
        limit = capacity;
        head->prev = NULL;
        tail->next = NULL;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto it = m.find(key); 
        if(it == m.end()){
            return -1;
        }
        int ans = it->second->value;

        remove(it->second);
        insert(key,ans,head);
        return ans;
    }
    void insert(int key,int value,Node *head){
        Node *newnode = new Node();
        newnode->key = key;
        newnode->value = value;
        m[key] = newnode;
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
        return;
    }
    void remove(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    void put(int key, int value) {
        auto it = m.find(key);
        if(it == m.end()){
            if(m.size()+1 <= limit){
                insert(key,value,head);
                return;
            }else{
                int lrukey = tail->prev->key;
                auto np = m[lrukey];
                m.erase(lrukey);
                remove(np);
                insert(key,value,head);
            }
        }else{
            auto np = it->second;
            remove(np);
            m.erase(it->first);
            insert(key,value,head);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */