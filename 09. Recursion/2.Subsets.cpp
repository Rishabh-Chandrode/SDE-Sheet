class Solution {
public:
vector<vector<int>> ans;
    void util(vector<int>& nums,vector<int> subans,int i,set<vector<int>>& s){
        if(i==nums.size()){
            sort(subans.begin(),subans.end());
            s.insert(subans);
            return;
        }

        util(nums,subans,i+1,s);
        subans.push_back(nums[i]);
        util(nums,subans,i+1,s);
        subans.pop_back();
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subans;
        set<vector<int>> s;
        util(nums,subans,0,s);
        for (auto it = s.begin(); it != s.end(); it++) {
            ans.push_back( * it);
        }
        return ans;
    }
};