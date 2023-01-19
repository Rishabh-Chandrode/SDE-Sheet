class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                count++;
            }else{
                ans=max(ans,count);
                count=0;
            }
        }
        ans = max(count,ans);
        return ans;
    }
};