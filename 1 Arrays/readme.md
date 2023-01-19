## 1) Set Matrix zeroes:

    use 0th row and column to mark for 0 
    mark (i,j)=0 if  (i,0)||(0,j) == 0;

---------------------------------------------------------------------------------------------------------
## 2) Pascal's Triangle:

---------------------


## 3) Next Permutation:

    We want to find a larger number, but not too large - just the next larger one =>
    We want to avoid chaning the number in the left - it will increase the number too much =>
    
    Example: 4325413 -> we can only change the last two numbers and have 432531
    What if it was 432531 in the first place? 31 cannot be increased.
    Lets try 531 - still no
    2531 - this can be incrased - the smallest number that can be used to incrase the 2 is 3. so for now we have 3521.
    Next we want to minimize 3521 - thats easier - just sort the numbers to the right of 3 - 3125. So the unswer is 4323125

---------------------------------------------------------------------------------------------------------

## 4) Maximum Subarray  #(Kadane’s Algorithm):

    Take the subarray sum until it is greater than zero.

---------------------------------------------------------------------------------------------------------
## 5) Sort Colors (Dutch National flag algorithm)
    In this approach, we will be using 3 pointers named low, mid, and high. We will be using these 3 
    pointers to move around the values. The primary goal here is to move 0s to the left and 2s to the 
    right of the array and at the same time all the 1s shall be in the middle region of the array and 
    hence the array will be sorted. 

---------------------------------------------------------------------------------------------------------
## 6) Best time to Buy and Sell Stock
    we Linearly traverse to array and keep the minimum updating each time a[i]>min
    and keep updating profit =a[i]-min if profit>maxprofit 



