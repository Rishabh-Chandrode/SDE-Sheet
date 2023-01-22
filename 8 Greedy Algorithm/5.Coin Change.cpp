class Solution {
public:
   
    int mincoin(vector<int>& coins,int amount,vector<int>& dp){
        if(amount==0) return 0;
        int n=coins.size();
        long long ans = INT_MAX;
        for(int i=0;i<n;i++){
            long long subans=0;
            if(amount-coins[i] >= 0){
                if(dp[amount-coins[i]]==-1)
                    subans = mincoin(coins,amount-coins[i],dp);
                else
                    subans = dp[amount-coins[i]];
                
                if(subans != INT_MAX && subans + 1 < ans) {
					ans = subans + 1;
				}
            }
        }
        dp[amount] = ans;
        return  ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        int ans = mincoin(coins,amount,dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};