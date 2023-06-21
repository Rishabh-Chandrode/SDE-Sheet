## 1)Rearrange Array Alternately
        To store two values on single index use 
        arr[i] = arr[i] + (arr[j]%z)*z;
        where z> arr[i] , z>arr[j] 

        visual:- arr[i]   arr[j]    =>   arr[i]arr[j]
                    i       j                   i

                    5       4                 45
        
        (arr[j]%z) is for if the number is already converted