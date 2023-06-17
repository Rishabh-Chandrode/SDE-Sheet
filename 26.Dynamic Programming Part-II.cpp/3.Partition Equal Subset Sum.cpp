

//Tabulation

class Solution {
public:
   
   
    bool canPartition(vector<int>& nums) {
            int sum=0;
            int n = nums.size();
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum&1) return false;
        sum = sum/2;


        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));

        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        
        for(int i=1;i<n;i++){
            for(int target = 1;target<=sum;target++){
                int take = false,nottake=false;
                if(target >= nums[i]) take =dp[i-1][target-nums[i]];
                nottake =dp[i-1][target];
                dp[i][target] = (take||nottake);
            }
        }
        return dp[n-1][sum];

        
    }
};


//Recursion + Memoization
class Solution {
public:
    bool util(int i,int target,vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;

        if(i>=nums.size()) return false;
        if(dp[i][target]!=-1)  return dp[i][target];
        int take = false,nottake=false;
        if(target >= nums[i]) take = util(i+1,target-nums[i],nums,dp);
        nottake = util(i+1,target,nums,dp);
        return dp[i][target] = (take||nottake);
    }
    bool canPartition(vector<int>& nums) {
            int sum=0;
            int n = nums.size();
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum&1) return false;
        sum = sum/2;

        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return util(0,sum,nums,dp);
    }
};