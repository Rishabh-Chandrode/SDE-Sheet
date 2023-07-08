## 1)N-th root of integer
        Apply binary search

## 2)Median of Row wise sorted matrix;
        low = min element in matrix
        high = max element in matrix
        apply binary search and find no of element <= mid

        for x to be median there will be (n/2) element less than x

## 3)Single element in a sorted array
        the first instance of every element is occurring on the even index and the second instance on the odd index.

## 4)Search in Rotated Sorted Array
        search for sorted array if target is not present in that array go for second array

## 5)Median of Two Sorted Arrays
        make partition of n/2 
                2 3 6   15 
                1 4     7 10 12 
        
        use low as 0 and high as the no of element in shorter array
        use binary search to choose no of element from 1 shorter array

## 6)K-th element of two sorted Arrays
        find element which has k no of element less than it

        binary search approach can be used:
        low will be the minimum no of elements that can be taken from the smaller array 
        i.e  low = max(0,k-m);
        high will be the maximum no of elements that can be taken from smaller array
        i.e high = min(n,k); you cant take more than k elements

        

## 7)Allocate minimum number of pages
        low will be min page of 1 book 
        high will be summ of all pages
        now we have a range, find mid and distribute it to m student 
        such that each student gets pages<=mid
        if pages lack decrease the no of pages (high = mid-1)
        if pages are access increase the pages (low = mid+1)

## 4)Aggressive Cows
        minimum distance between two cows = 1 = low
        max distance between two cows = last pos - firstpos = high
        find mid and place cows