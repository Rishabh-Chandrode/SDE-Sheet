## 1)Rotate LL
        Steps to the algorithm:-
            Calculate the length of the list.
            Connect the last node to the first node, converting it to a circular linked list.
            Iterate to cut the link of the last node and start a node of k%length of the list
            rotated list.

## 2)Copy List with Random Pointer
        1  2  3  4  5
          1  2  3  4  5

        p->next->random = p->random->next;

 