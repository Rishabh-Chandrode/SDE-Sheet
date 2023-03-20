## 1)Next Smaller Element
        same as next bigger element 
        make a stack traverse from end keep the smaller elements

## 2)LRU Cache
        use a unordered map and double linked list to stare least recently used cashe

## 3)LFU Cache
        https://leetcode.com/problems/lfu-cache/editorial/

## 4)Largest Rectangle in Histogram
        find right smaller and left smaller value for i
        that will be the width

## 5)Sliding Window Maximum
        We address this problem with the help of a data structure that keeps checking whether the incoming element is larger than the already present elements. This could be implemented with the help of a de-queue. When shifting our window, we push the new element in from the rear of our de-queue. Following is a sample representation of our dequeue.

        Every time before entering a new element, we first need to check whether the element present at the front is out of bounds of our present window size. If so, we need to pop that out. Also, we need to check from the rear that the element present is smaller than the incoming element. If yes, there’s no point storing them and hence we pop them out. Finally, the element present at the front would be our largest element.

## 6) Min Stack
        O(2N) make a linked list or stack with
        {
                prev;
                val;
                min;
                next;
        }
        O(N)
                use formula 2*val-min;
