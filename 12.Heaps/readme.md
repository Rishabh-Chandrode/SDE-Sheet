## 1)Heap Implementation
        Heap implementation using arrays

        parrent of i = floor(i/2);
        left child of i = i*2;`
        right child of i = (i*2)+1;

## 2)kth largest element
        make_heap(): Converts given range to a heap.

        push_heap(): Arrange the heap after insertion at the end.

        pop_heap(): Moves the max element at the end for deletion.(doesn't remove the element)
                    use heap.pop_back() to remove element from list.

        sort_heap(): Sort the elements of the max_heap to ascending order.

        is_heap(): Checks if the given range is max_heap.

        is_heap_until(): Returns the largest sub-range that is max_heap.

## 3) Combinational sum
        Youtube pe dekh le bhai

## 4)Find Median from Data Stream
        create two heaps one for first half and one for second half

## 5)Merge k sorted arrays
        push into heap pop from heap

## 6)K most frequent elements
        count frequency of each element by map
        put map element into heap
        pop from heap and return ans;
