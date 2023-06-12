class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++){

            int sum=nums[i];
            int low=i+1,high=n-1;
            while(low<high){
                sum= nums[i] + nums[low] + nums[high];
                if(sum  == 0){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[low]);
                    v.push_back(nums[high]);
                    ans.push_back(v);
                     while(low<high && nums[low]==nums[low+1]) low++;
                while(low<high && nums[high]==nums[high-1] ) high--;

                low++;
                high--;
                }else if(sum > 0){
                    high--;
                }else if(sum<0){
                    low++;
                }
               
            }
            while(i<n-2 && nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};