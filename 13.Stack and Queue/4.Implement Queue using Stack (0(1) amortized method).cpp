class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()){
            int t = s2.top();
        s2.pop();
        return t;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();

        }
        int t = s2.top();
        s2.pop();
        return t;
    }
    
    int peek() {
        if(!s2.empty()){
           return s2.top();
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();

        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        return false;
    }
};
