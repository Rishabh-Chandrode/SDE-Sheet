class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        v=intervals[0];
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                if(intervals[i][0]<start){
                    start=intervals[i][0];
                }
                if(intervals[i][1]>end){
                    end=intervals[i][1];
                }
                v[0]=start;
                v[1]=end;
            }else{
                ans.push_back(v);
                v=intervals[i];
                start=v[0];
                end=v[1];
            }
        }
        ans.push_back(v);
        return ans;
    }
};