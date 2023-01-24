class Solution {
public:
    vector<vector<int>> ans;
    void util(vector<int>& candidates,int target,int index,vector<int> subans){
        if(target == 0){
            ans.push_back(subans);
            return ;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i]>target) return;
            subans.push_back(candidates[i]);
            util(candidates,target-candidates[i],i+1,subans);
            subans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> subans;
        util(candidates,target,0,subans);
        return ans;
    }
};