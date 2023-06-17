//Recursion + Memoization
class Solution {
public:
    int util(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(ind >= coins.size()){
            if(amount == 0){
                return 0;
            }else{
                return 1e9;
            }
        }
        if(amount == 0) return 0;

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int take = 1e9,nottake;
        nottake = util(ind+1,amount,coins,dp);
        if(amount >= coins[ind]) take = 1+ util(ind,amount-coins[ind],coins,dp);

        return dp[ind][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        int ans = util(0,amount,coins,dp);
        return (ans== 1e9) ? -1 :ans;
    }
};