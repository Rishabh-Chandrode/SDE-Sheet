int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        if(n<2) return n;
        if(n==2 && A[0]+A[1]==0) return 2;
        map<int,vector<int>> m; 
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            m[sum].push_back(i);
        }
        int dis=0;
        for(auto i:m){
            if(i.first==0){
                dis=max(dis,i.second[i.second.size()-1]+1);
            }
            if(i.second.size()>1){
                dis=max(dis, (i.second[i.second.size()-1] -  i.second[0] ) );
            }
        }
        return dis;
    }