class Solution {
public:
int dp[301];
    bool solve(string s,set<string> set,int i){
        if(i==s.size()) return true;
        string temp="";
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<s.size();j++){
            temp += s[j];
            if(set.find(temp) != set.end()){
                if(solve(s,set,j+1)) return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> set(wordDict.begin(),wordDict.end());
        memset(dp,-1,sizeof(dp));
        return solve(s,set,0);
    }
};