vector<int> ans;
    void util(vector<int>& arr,int N,int i,int sum){
        if(i==N) {
            ans.push_back(sum);
            return;
        }
        
        util(arr,N,i+1,sum);
        util(arr,N,i+1,sum+arr[i]);
        
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        util(arr,N,0,0);
        return ans;
    }