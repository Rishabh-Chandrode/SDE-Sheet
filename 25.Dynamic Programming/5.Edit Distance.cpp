
//tabulation + space optimization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1 == 0) return n2;
        if(n2==0) return n1;
        vector<int>prev (n2+1,0);
        vector<int>curr (n2+1,0);
        for(int i=0;i<=n2;i++){
            prev[i] = i;
        }

        for(int i=1;i<=n1;i++){
            curr[0] = i;
            for(int j=1;j<=n2;j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1];
                }else{
                    curr[j] = 1+min(prev[j-1],min(prev[j],curr[j-1]));
                }
            }
            prev = curr;
        }
        return curr[n2];

    }
};


//Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int i=0;i<=n1;i++){
            dp[i][0] = i;
        }
        for(int i=0;i<=n2;i++){
            dp[0][i] = i;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[n1][n2];

    }
};


//Recursion + memoization
class Solution {
public:

    int util(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j] !=-1) return dp[i][j];

        if(s1[i] == s2[j]){
            return  dp[i][j] = util(i-1,j-1,s1,s2,dp);
        }else{
            return dp[i][j] = 1+min(util(i-1,j-1,s1,s2,dp),min(util(i-1,j,s1,s2,dp),util(i,j-1,s1,s2,dp)));
        }
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return util(n1-1,n2-1,word1,word2,dp);
    }
};