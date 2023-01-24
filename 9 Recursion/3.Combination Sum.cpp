class Solution {
public:
    vector<vector<int>> ans;
    void util(vector<int>& candidates,int target, int sum, vector<int> subans,int i){
       if(sum>target || i==candidates.size()) return;
       if(sum == target){
           ans.push_back(subans);
           return;
       }
       subans.push_back(candidates[i]);
       util(candidates,target,sum+candidates[i],subans,i);
       subans.pop_back();
       util(candidates,target,sum,subans,i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subans;
        util(candidates, target, 0, subans, 0);
        return ans;
    }
};