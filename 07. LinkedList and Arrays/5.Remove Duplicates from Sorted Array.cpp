class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int ele = nums[0],ind=0;
        for(int i=1;i<n;i++){
           if(nums[i]!=ele){
               ind++;
               nums[ind] = nums[i];
               ele = nums[i];
           }
        }
        return ind+1;
    }
};