//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool is_Palindrome(int i,int j,string& s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
            
        }
        return true;
    }
    
    // Tabulation
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int ans = 1e9;
            for(int k=i;k<n;k++){
                if(!is_Palindrome(i,k,str)){
                    continue;
                }
                int right =dp[k+1];// f(k+1,n,str,dp);
                ans = min(ans,right);
            }
            dp[i] = 1+ans;
        }
        return dp[0]-1;
        
    }
    


    //Recursion + memoization
    int f(int i,int n,string &str,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = 1e9;
        for(int k=i;k<n;k++){
            if(!is_Palindrome(i,k,str)){
                continue;
            }
            int right = f(k+1,n,str,dp);
            ans = min(ans,right);
        }
        return dp[i] = 1+ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n+1,-1);
        return f(0,n,str,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends