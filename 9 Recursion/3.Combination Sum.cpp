class Solution {
public:
    vector<vector<int>> ans;
    void util(vector<int>& candidates,int target, int sum, vector<int> subans,int i){
       if(i == candidates.size()) return;
       subans.push_back(candidates[i]); 
       sum += candidates[i];
       
       if(sum > target) return;
       if(sum == target){
           ans.push_back(subans);
           return;
       }
       
       util(candidates,target,sum,subans,i);
       subans.pop_back();
       util(candidates,target,sum,subans,i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subans;
        util(candidates, target, 0, subans, 0);
        return ans;
    }
};