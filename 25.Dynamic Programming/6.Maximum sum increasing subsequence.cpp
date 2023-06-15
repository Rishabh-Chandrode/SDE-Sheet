
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:


    //Algorithmic approach
    int maxSumIS_algo(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<int> dp(n,0);
	    for(int i=0;i<n;i++) dp[i] = arr[i];
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if( arr[i] > arr[j] && dp[j]+arr[i] > dp[i]  ){
	                dp[i] = dp[j] + arr[i];
	            }
	        }
	       
	        
	    }
	    int ans=0;
	    for(int i=0;i<n;i++){
	        ans = max(ans,dp[i]);
	    }
	    return ans;
	}  




    //Recursion + Memoization

	int util(int ind,int prevind,int n,int arr[],vector<vector<int>>& dp){
	    if(ind>=n) return 0;
	    
	    
	    if( dp[ind][prevind+1] != -1) return dp[ind][prevind+1];
	    int ans = 0;
	    
	    if(prevind == -1 || arr[prevind] < arr[ind]){
	        ans = arr[ind] + util(ind+1,ind,n,arr,dp);
	    }
	    dp[ind][prevind+1] = max(ans,util(ind+1,prevind,n,arr,dp));
	    return dp[ind][prevind+1];
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
	    
	    return util(0,-1,n,arr,dp);
	}  

    
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends