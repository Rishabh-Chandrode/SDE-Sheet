//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    
	    int high=m,low=1,num;
	    while(high-low>1){
	        num = (high+low)/2;
	        if(pow(num,n) == m) return num;
	        if(pow(num,n) < m) low = num;
	        if(pow(num,n) > m) high = num;
	    }
	    if(pow(low,n) == m) return low;
	    if(pow(high,n) == m) return high;
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends