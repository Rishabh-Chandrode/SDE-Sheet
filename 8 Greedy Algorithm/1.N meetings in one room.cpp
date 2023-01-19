int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>> v;
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> t;
            t.push_back(end[i]);
            t.push_back(start[i]);
            v.push_back(t);
        }
        sort(v.begin(),v.end());
        int time=-1;
        for(int i=0;i<v.size();i++){
            if(v[i][1]>time){
                ans++;
                time = v[i][0];
            }
        }
        return ans;
    }