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