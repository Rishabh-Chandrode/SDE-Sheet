class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int i = 1, j = 0, n = str.size();
        vector<int> dp(n+1,0);
        while( i < str.size() ){
            if( str[i] == str[j] ) dp[++i]=++j;
            else if( j == 0 ) i++;
            else j = dp[j];
        }
        for(int i=0;i<n+1;i++){
            cout<<dp[i]<<" ";
        }
        return dp[n]&&dp[n]%(n-dp[n])==0;
    }
    
};