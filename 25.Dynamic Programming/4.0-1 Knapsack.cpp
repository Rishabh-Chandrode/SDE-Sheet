//Recursive + Memoization

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    
    int util(int i,int wt[],int val[],int n,int W,vector<vector<int>> dp){
        if(i>=n) return 0;
          
    
        
        if(dp[i][W]!=-1) return dp[i][W];
        
        int nottake = util(i+1,wt,val,n,W,dp);
        int take = INT_MIN;
        if(W >= wt[i]) take =val[i] + util(i+1,wt,val,n,W-wt[i],dp);
        
        return dp[i][W] = max(take,nottake);
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack_rm(int W, int wt[], int val[], int n) 
    { 

      vector<vector<int>> dp(n,vector<int> (W+1,-1));
      return util(0,wt,val,n,W,dp);
    }

    //Tabulation + space optimization
     int knapSack_ts(int W, int wt[], int val[], int n) 
    { 
        // Your code here
        
         vector<int> next (W+1,0);
         vector<int> curr(W+1,0);
         for(int i=n-1;i>=0;i--){
             for(int cap=0;cap<=W;cap++){
                 int nottake = next[cap];
                 int take=INT_MIN;
                 if(cap+wt[i] <= W)
                    take =val[i] +next[cap+wt[i]];
                 curr[cap] = max(take,nottake);
             }
             next = curr;
         }
         return curr[0];
    }


    //Tabulation
    int knapSack_t(int W, int wt[], int val[], int n) 
    { 
        // Your code here
         vector<vector<int>> dp(n+1,vector<int> (W+1,0));
         for(int i=n-1;i>=0;i--){
             for(int cap=0;cap<=W;cap++){
                 int nottake = dp[i+1][cap];
                 int take=INT_MIN;
                 if(cap+wt[i] <= W)
                    take =val[i] +dp[i+1][cap+wt[i]];
                 dp[i][cap] = max(take,nottake);
             }
         }
         return dp[0][0];
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack_ts(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends