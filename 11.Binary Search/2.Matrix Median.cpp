//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here
        int n = (R*C)/2;
        int mid;
         int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            for(int j=0;j<C;j++){
                if (matrix[i][j] < low)
                    low = matrix[i][j];
     
                if (matrix[i][j] > high)
                    high = matrix[i][j];
            }
            
        }
        
        int count=0;
        
        while(low<high){
            mid = (high+low)/2;
            count=0;
            for(int i=0;i<R;i++){
                
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
               // cout<<i<<" "<<count<<endl;
            } 
            if(count<= (R * C) / 2){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends