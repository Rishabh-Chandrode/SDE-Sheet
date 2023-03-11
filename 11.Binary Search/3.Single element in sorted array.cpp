class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int mid;
        while(low<=high){
            mid = (high+low)/2;
            if(mid-1>0 && mid+1<nums.size() && nums[mid]!= nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid&1){
                if(nums[mid] == nums[mid-1]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }else{
                if(mid+1<nums.size() && nums[mid] == nums[mid+1]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }

        }
        return nums[mid];
    }
};