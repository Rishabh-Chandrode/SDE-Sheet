class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int n=0;
        for(int i=0;i<numRows;i++){
            vector<int> t;
            t.push_back(1);
            for(int j=1;j<n;j++){
                int temp;
                temp=ans[i-1][j-1]+ans[i-1][j];
                t.push_back(temp);
            }
            if(i!=0)t.push_back(1);
            ans.push_back(t);
            n++;
        }
        return ans;
    }
};