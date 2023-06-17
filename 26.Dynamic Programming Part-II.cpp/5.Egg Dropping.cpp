//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{   private:

        //Tabulation
         int eggDrop_T(int n, int k) 
        {
            // your code here
            
            vector<vector<int>> dp(k+1,vector<int>(n+1,0));
            
            for(int i=0;i<=k;i++){
                dp[i][1] = i;
            }
            for(int i=0;i<=n;i++){
                dp[1][i] = 1;
            }
            
            for(int floors = 2;floors<=k;floors++){
                for(int eggs=2;eggs<=n;eggs++){
                    
                    int ans = 1e9;
                    for(int i=1;i<=floors;i++){
                        int b =dp[i-1][eggs-1];
                        int nb = dp[floors-i][eggs];
                        
                        int t = max(b,nb);
                        
                        ans = min(ans,t);
                    }
                    dp[floors][eggs] = 1+ans;
                    
                }
            }
            return dp[k][n];
        }





        //Recursion + Memoization
        int f(int floors,int eggs,vector<vector<int>>& dp){
            if(eggs ==1 ) return floors;
            if(floors ==0 || floors == 1) return floors;
            if(dp[floors][eggs] !=-1) return dp[floors][eggs]; 
            int ans = 1e9;
            for(int i=1;i<=floors;i++){
                int b = f(i-1,eggs-1,dp);
                int nb = f(floors-i,eggs,dp);
                
                int t = max(b,nb);
                
                ans = min(ans,t);
            }
            return dp[floors][eggs] = 1+ans;
        }
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return f(k,n,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends