class Solution {
private:
    bool isPresent(string s,vector<string>& wordDict){
        if(find(wordDict.begin(),wordDict.end(),s) == wordDict.end())
            return false;

        return true;
    }
    int f(int i,int j,string& s,vector<string>& wordDict,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(isPresent(s.substr(i,j-i+1),wordDict) ){
            return 1;
        }

        for(int k=i;k<j;k++){
            int left = f(i,k,s,wordDict,dp);
            int right = f(k+1,j,s,wordDict,dp);

            if(left && right)  return dp[i][j] = 1;
        }
        return dp[i][j] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,s.size()-1,s,wordDict,dp);
    }
};