int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
        sort(arr,arr+n);
        sort(dep,dep+n);
        int i=0,j=1,ans=1;
        while(j<n && i<n){
           if(arr[j] > dep[i] ){
               i++;
               j++;
           }else{
               ans++;
               j++;
           }
        }
        return ans;
    }