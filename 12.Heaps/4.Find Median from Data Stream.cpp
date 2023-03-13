class MedianFinder {
public:
    MedianFinder() {
       
    }
     priority_queue<int> maxheap;
        priority_queue <int, vector<int>, greater<int> > minheap;
    void addNum(int num) {
        if(maxheap.empty()) {
            maxheap.push(num);
            return;
        }
        if(minheap.empty()){
            if(num >= maxheap.top()){
                minheap.push(num);
                return;
            }else{
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
                return;
            }
        }
        

        if(num < maxheap.top()){
            if(maxheap.size() == minheap.size()){
                maxheap.push(num);
            }else{
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
            }
        }else if(num > minheap.top()){
            if(maxheap.size() == minheap.size()){
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(num);
            }else{
               minheap.push(num);
            }
        }else{
            if(maxheap.size() == minheap.size()){
                maxheap.push(num);
            }else{
                minheap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(minheap.empty()){
            return maxheap.top();
        }
        if(maxheap.size() == minheap.size()){
            return (double)(maxheap.top() + minheap.top())/2;
        }
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */