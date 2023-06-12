#include <bits/stdc++.h> 
#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
    int num=0;
    for(int i=0;i<n;i++){
        num^=arr[i];
        num^=(i+1);
        
    }
    //cout<<num<<"--"<<endl;
    int ind;
    for(int i=31;i>=0;i--){
        if( (num>>i) & 1) {
            ind=i;
            break;
        }
    }
   // cout<<ind<<";"<<endl;
    
    int num0=0,num1=0;
    for(int i=0;i<n;i++){
        if(((arr[i]>>ind)&1)) {
            num1^=arr[i];
        }
        else {
            num0^=arr[i];
        }
        
        if((((i+1)>>ind)&1)) {
            num1^=(i+1);
        }
        else {
            num0^=(i+1);
        }
    }
    pair<int,int> ans;
    ans.first=min(num1,num0);
    ans.second=max(num1,num0);
    return ans;
    
	
}
