## 1)Search in 2d matrix
        Binary search

## 2)Pow(x,n)
        search ans by binary method
            if( (nn%2)==0 ){
                x=(x*x);
                nn= (nn/2);
            }else{
                ans=ans*x;
                nn=(nn-1);
            }

## 3)Majority Element ( Moore’s Voting Algorithm )
        we can say that count of minority elements and majority elements are equal up to a certain point
        of time in the array. So when we traverse through the array we try to keep track of the count of elements and which element we are tracking. Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the majority element. 

        Approach: 

        Initialize 2 variables: 
        Count –  for tracking the count of element
        Element – for which element we are counting
        Traverse through nums array.
        If Count is 0 then initialize the current traversing integer of array as Element 
        If the traversing integer of array and Element are same increase Count by 1
        If they are different decrease Count by 1
        The integer present in Element is the result we are expecting 
        