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

## 6)K-th element of two sorted Arrays
        find element which has k no of element less than it

## 7)Allocate minimum number of pages
        low will be min page of 1 book 
        high will be summ of all pages
        now we have a range, find mid and distribute it to m student 
        such that each student gets pages<=mid
        if pages lack decrease the no of pages (high = mid-1)
        if pages are access increase the pages (low = mid+1)