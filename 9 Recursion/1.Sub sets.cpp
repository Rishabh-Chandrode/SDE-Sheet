class Solution {
public:
vector<vector<int>> ans;
    void util(vector<int>& nums,vector<int>& subans,int i){
        if(i == nums.size()){
            ans.push_back(subans);
            return;
        }

        util(nums,subans,i+1);
        
        subans.push_back(nums[i]);
        util(nums,subans,i+1);
        subans.pop_back();
      

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subans;
        util(nums,subans,0);
        return ans;
    }
};