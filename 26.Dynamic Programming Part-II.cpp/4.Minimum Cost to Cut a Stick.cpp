class Solution {
public:


    //Recursion + Memoization
    int f(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        if(j-i<=1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1e9;

        for(int k = i+1;k<j;k++){
            int cost = (cuts[j] - cuts[i]) + f(i,k,cuts,dp) + f(k,j,cuts,dp);
            ans = min(ans,cost);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+2,vector<int>(c+2,-1));
        return f(0,cuts.size()-1,cuts,dp);
    }
};