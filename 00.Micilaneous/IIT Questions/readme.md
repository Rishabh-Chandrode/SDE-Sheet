## 1)Rearrange Array Alternately
        To store two values on single index use 
        arr[i] = arr[i] + (arr[j]%z)*z;
        where z> arr[i] , z>arr[j]

        z can be any number greater than all the other numbers 

        visual:- arr[i]   arr[j]    =>   arr[i]arr[j]
                    i       j                   i

                    5       4                 45
        
        (arr[j]%z) is for if the number is already converted

## 2)Find duplicates in an array
        since the no are between 0 to n-1
        increment arr[arr[i]] by n in one loop
        and second loop divide it by n to find the frequency of that element