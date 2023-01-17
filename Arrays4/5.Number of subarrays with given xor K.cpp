#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    map<int,int> m;
    int n=arr.size();
    int xo=0;
    int ans=0;
    for(int i=0;i<n;i++){
        xo=(xo^arr[i]);
        int t=(xo^x);
        if(xo==x) ans++;
        if(m.find(t)!=m.end()){
            
            ans+=m[t];
            
        }
        
            m[xo]++;
        
    }
    return ans;
}