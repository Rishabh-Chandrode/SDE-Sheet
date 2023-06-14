class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()<=1) return nums[0];
        int fp=1,bp=1,mp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                fp=1;
                continue;
            }
            fp*=nums[i];
            mp = max(mp,fp);
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==0){
                bp = 1;
                continue;
            }
            bp *= nums[i];
            mp = max(mp,bp);
        }
        return mp;
    }
};