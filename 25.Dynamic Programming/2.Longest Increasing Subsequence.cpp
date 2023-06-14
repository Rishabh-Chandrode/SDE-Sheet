//Binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for(int i=0;i<n;i++){
            auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
            if(it == dp.end()){
                dp.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
        }
        return dp.size();
        
    }
};



//Algorithmic approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]< nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int ans=1;
        for(int i=0;i<n;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};


// Recursion + Memoiztion
class Solution {
public:
    int util(int i,int prevind,vector<int>& nums,vector<vector<int>>& dp){
       if(i==nums.size()) return 0;
        if(dp[i][prevind+1] != -1) return dp[i][prevind+1];
       int len = util(i+1,prevind,nums,dp);
       if(prevind==-1 || nums[i]>nums[prevind]){
           len = max(len,1+util(i+1,i,nums,dp));
       }
       return dp[i][prevind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        if(nums.size()==0) return 0;
       int maxsize = 1;
       return util(0,-1,nums,dp);
    }
};


//Bottom up approach Tabulation

class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        int ind,prevind;
        for(ind =n-1;ind>=0;ind--){
            for(prevind = ind-1;prevind>=-1;prevind--){
                int len = dp[ind+1][prevind+1];
                if(prevind==-1 || nums[ind]>nums[prevind]){
                    len = max(len,1+dp[ind+1][ind+1]);
                }
                dp[ind][prevind+1] = len;

            }
        }
        return dp[0][0];
    }
};



//space optimization in tabulation

class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);
        int ind,prevind;
        for(ind =n-1;ind>=0;ind--){
            for(prevind = ind-1;prevind>=-1;prevind--){
                int len = next[prevind+1];
                if(prevind==-1 || nums[ind]>nums[prevind]){
                    len = max(len,1+next[ind+1]);
                }
                curr[prevind+1] = len;

            }
            next = curr;
        }
        return curr[0];
    }
};