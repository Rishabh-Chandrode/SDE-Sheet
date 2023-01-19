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

## 3)3sum
        sort the array.
        one loop for i 
        and anathor loop for low and high

## 4)Traping rain water
        Solution 3:Optimal Solution(Two pointer approach)

            Approach: Take 2 pointer l(left pointer) and r(right pointer) pointing to 0th and (n-1)th
            index respectively.Take two variables leftMax and rightMax and initialise it to 0.If heigh
            [l] is less than or equal to height[r] then if leftMax is less then height[l] update leftMax 
            to height[l] else add leftMax-height[l] to your final answer and move the l pointer to the 
            right i.e l++.If height[r] is less then height[l],then now we are dealing with the right 
            block.If height[r] is greater then rightMax,then update rightMax to height[r] else add 
            rightMax-height[r] to the final answer.Now move r to the left. Repeat theses steps till l 
            and r crosses each other.

            Intuition: We need a minimum of leftMax and rightMax.So if we take the case when height[l]
            <=height[r] we increase l++, so we can surely say that there is a block with a height more 
            than height[l] to the right of l. And for the same reason when height[r]<=height[l] we can 
            surely say that there is a block to the left of r which is at least of height[r]. So by 
            traversing these cases and using two pointers approach the time complexity can be decreased 
            without using extra space.
