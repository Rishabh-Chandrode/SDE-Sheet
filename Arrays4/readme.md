## 1)Two Sum
        Use hash map to store index of element 
        search for target-nums[i] value in map

## 2)4 Sum
        Approach: 
        Sort the array, and then fix two pointers, so the remaining sum will be (target – (nums[i] + 
        nums[j])). Now we can fix two-pointers, one front, and another back, and easily use atwo
        -pointer to find the remaining two numbers of the quad. In order to avoid duplications, 
        we jump the duplicates, because taking duplicates will result in repeating quads. We can 
        easily jump duplicates, by skipping the same elements by running a loop.

## 3)Longest Consecutive Sequence
        Approach: We will first push all are elements in the HashSet. Then we will run a for loop and 
        check for any number(x) if it is the starting number of the consecutive sequence by checking if 
        the HashSet contains (x-1) or not. If ‘x’ is the starting number of the consecutive sequence we 
        will keep searching for the numbers y = x+1, x+2, x+3, ….. And stop at the first ‘y’ which is 
        not present in the HashSet. Using this we can calculate the length of the longest consecutive 
        subsequence. 

## 4)Largest subarray with sum 0
        So in this problem, we’ll store the prefix sum of every element, and if we observe that 2 
        elements have same prefix sum, we can conclude that the 2nd part of this subarray sums to zero

## 5)No. of subarray with given XOR

        |<-------XOR------->|
        --------------------------
        |<----y---->|<--x-->|

        To find given x:-
                XOR = x^y
                x=y^XOR
        
        find suitable y for ezch xor using hash table.