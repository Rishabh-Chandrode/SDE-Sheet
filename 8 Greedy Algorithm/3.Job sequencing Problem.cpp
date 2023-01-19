static bool comp(Job a,Job b){
        return a.profit > b.profit;
}
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        
       
        int maxdead=0;
        for(int i=0;i<n;i++){
            maxdead = max(maxdead,arr[i].dead);
        }
         vector<int> ans;
        ans.push_back(0);
        ans.push_back(0);
        vector<int> v(maxdead+1,1);
        for(int i=0;i<n;i++){
            int j=arr[i].dead-1;
            while(j>=0){
                if(v[j]){
                    v[j]=0;
                    ans[0]++;
                    ans[1]+=arr[i].profit;
                    j=0;
                }
                j--;
            }
        }
        return ans;
    } 
