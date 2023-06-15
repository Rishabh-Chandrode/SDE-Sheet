
//Space optimization in tabulation

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int>next (m+1,0);   // j is itterating on both curr and next vector
        vector<int>curr (m+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i] == text2[j]){
                    curr[j] = 1+ next[j+1];
                }else{
                    curr[j] = max(next[j],curr[j+1]);
                }
            }
            next = curr;
        }
        return curr[0];

    }
};



//Tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1+ dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];

    }
};

//Recursion + Memoization
class Solution {
public:
    int util(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i==s1.size() || j==s2.size()) 
            return 0;

        int ans=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i] == s2[j]){
            ans = 1+ util(i+1,j+1,s1,s2,dp);
        }else{
            ans = max ( util(i,j+1,s1,s2,dp),util(i+1,j,s1,s2,dp) );
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return util(0,0,text1,text2,dp);

    }
};