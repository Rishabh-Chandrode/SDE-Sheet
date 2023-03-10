class Solution {
public:


    void util(vector<vector<int>>& ans,vector<int> nums,int i){
        if(i==nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            util(ans,nums,i+1);
        }
        

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        util(ans,nums,0);
        return ans;
    }
};